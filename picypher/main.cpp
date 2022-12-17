#include <iostream>
#include <string>
#include "picypher.h"

int main(int argc, char const *argv[])
{
    string input;
    string key;
    getline(cin, input);
    cin >> key;

    input = Picypher::encode(input, key);
    cout << input << endl
         << endl;

    input = Picypher::decode(input, key);
    cout << input << endl;

    return 0;
}
