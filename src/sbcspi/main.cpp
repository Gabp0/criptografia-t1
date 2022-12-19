#include <iostream>
#include <string>
#include "sbcspi.h"

int main(int argc, char const *argv[])
{
    string input;
    string key;
    getline(cin, input);
    cin >> key;

    input = SBCS314::encode(input, key);
    cout << input << endl
         << endl;

    input = SBCS314::decode(input, key);
    cout << input << endl;

    return 0;
}
