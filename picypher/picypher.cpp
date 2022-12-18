#include "picypher.h"
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <gmp.h>
#include <string>

using namespace std;

string Picypher::encode(string plaintext, string key)
{
    string output; // output string

    plaintext = treatment(plaintext);
    key = convertKey(key);

    string pip = genPip(stoi(key.substr(0, 2)));
    unsigned int f_offset = stoi(key.substr(1, 5));

    mpz_t offset;
    mpz_init(offset);
    mpz_set_ui(offset, f_offset);

    mpz_t pip_pos;
    mpz_init(pip_pos);

    for (size_t i = 0; i < ((plaintext.size() / BLOCK_SIZE) + 1); i++)
    {
        string sub = plaintext.substr(i * BLOCK_SIZE, BLOCK_SIZE); // split into MIN_BLOCK_SIZE size substrings

        for (size_t j = 0; j < ITR_NUM; j++)
        {
            mpz_set_ui(offset, f_offset);
            mpz_pow_ui(offset, offset, pow(2, j));
            mpz_mod_ui(pip_pos, offset, pip.size());
            unsigned int off_mod = mpz_get_ui(pip_pos);

            int k = 0;
            for (char c : sub)
            {
                int coff = pip[(off_mod + k) % pip.size()] - '0';

                sub[k] = offsetChar(c, coff);
                k++;
            }
        }

        output += sub;
    }

    return output;
}

string Picypher::decode(string cypheredtext, string key)
{
    string output; // output string

    key = convertKey(key);
    string pip = genPip(stoi(key.substr(0, 2)));
    unsigned int f_offset = stoi(key.substr(1, 5));

    mpz_t offset;
    mpz_init(offset);
    mpz_set_ui(offset, f_offset);

    mpz_t pip_pos;
    mpz_init(pip_pos);

    for (size_t i = 0; i < ((cypheredtext.size() / BLOCK_SIZE) + 1); i++)
    {
        string sub = cypheredtext.substr(i * BLOCK_SIZE, BLOCK_SIZE); // split into MIN_BLOCK_SIZE size substrings

        for (int j = ITR_NUM - 1; j >= 0; j--)
        {
            mpz_set_ui(offset, f_offset);
            mpz_pow_ui(offset, offset, pow(2, j));
            mpz_mod_ui(pip_pos, offset, pip.size());
            unsigned int off_mod = mpz_get_ui(pip_pos);

            int k = 0;
            for (char c : sub)
            {
                int coff = pip[(off_mod + k) % pip.size()] - '0';

                sub[k] = offsetChar(c, -coff);
                k++;
            }
        }

        output += sub;
    }

    return output;
}

string Picypher::convertKey(string key)
{
    string int_key;

    size_t i = 0;
    while (int_key.size() < KEY_SIZE)
    {
        int_key += to_string(key[i] - '0');
        i++;
    }

    return int_key;
}

string Picypher::genPip(int pow)
{
    char pip[32536];

    mpz_t pi; // initialize gmp number (beeg pi)
    mpz_init(pi);
    mpz_set_str(pi, pi_str, 10);

    mpz_pow_ui(pi, pi, pow);  // pi^key[0:1]
    mpz_get_str(pip, 10, pi); // convert back to char

    string pip_str = pip;

    return pip_str;
}

string Picypher::treatment(string input)
// treat the string
{
    // transform(input.begin(), input.end(), input.begin(), ::toupper); // convert to uppercase
    for (char i : input)
    {
        if ((i > 126) || (i < 32)) // replace char other than letters
        {
            replace(input.begin(), input.end(), i, 'X');
        }
    }

    return input;
}

char Picypher::offsetChar(char c, int offset)
{
    int out = c + offset;
    if (out > 126)
    {
        out = (out - 126) + 32;
    }
    else if (out < 32)
    {
        out = (out - 32) + 126;
    }
    return out;
}