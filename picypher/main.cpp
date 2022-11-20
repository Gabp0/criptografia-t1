#include <iostream>
#include <string>
#include "picypher.h"

int main(int argc, char const *argv[])
{
    string input;
    int key;
    getline(cin, input);
    cin >> key;

    input = Picypher::encode(input, key);
    cout << input << endl;

    input = Picypher::decode(input, key);
    cout << input << endl;

    return 0;
}
