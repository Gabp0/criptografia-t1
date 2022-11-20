#include "picypher.h"
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>

string Picypher::encode(string plaintext, unsigned long long key)
{
    string output; // output string
    plaintext = treatment(plaintext);

    for (size_t i = 0; i < ((plaintext.size() / BLOCK_SIZE) + 1); i++)
    {
        string sub = plaintext.substr(i * BLOCK_SIZE, BLOCK_SIZE); // split into MIN_BLOCK_SIZE size substrings

        cout << key << endl;
        int curr_key = key % (10 * CKEY_SIZE); // key for the current block
        key /= 10 * CKEY_SIZE;

        cout << curr_key << endl;
        unsigned long long offset = curr_key * pi; // letters offset
        cout << offset << endl;
        for (char i : sub)
        {
            int d = offset % 10;
            offset /= 10;

            output += offsetChar(i, d);
        }
    }

    return output;
}

string Picypher::decode(string cypheredtext, unsigned long long key)
{
    string output; // output string

    for (size_t i = 0; i < ((cypheredtext.size() / BLOCK_SIZE) + 1); i++)
    {
        string sub = cypheredtext.substr(i * BLOCK_SIZE, BLOCK_SIZE); // split into MIN_BLOCK_SIZE size substrings

        int curr_key = key % (10 * CKEY_SIZE); // key for the current block
        key /= 10 * CKEY_SIZE;

        unsigned long long offset = curr_key * pi; // letters offset
        for (char i : sub)
        {
            int d = offset % 10;
            offset /= 10;

            output += offsetChar(i, -d);
        }
    }

    return output;
}

string Picypher::treatment(string input)
// treat the string
{
    transform(input.begin(), input.end(), input.begin(), ::toupper); // convert to uppercase
    for (char i : input)
    {
        if ((i > 90) || (i < 65)) // replace char other than letters
        {
            replace(input.begin(), input.end(), i, 'X');
        }
    }

    for (size_t i = 0; i < BLOCK_SIZE - (input.size() % BLOCK_SIZE); i++) // fill the rest of the string
    {
        input += 'X';
    }

    return input;
}

char Picypher::offsetChar(char c, int offset)
{
    char out = c + offset;
    if (out > 90)
    {
        out = (out - 90) + 65;
    }
    else if (out < 65)
    {
        out = (out - 65) + 90;
    }
    return out;
}