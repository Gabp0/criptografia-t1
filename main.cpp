#include <iostream>
#include <algorithm>
#include "picypher/picypher.h"
#include "sauce/vigenere.h"

using namespace std;

char *getCmdOption(char **begin, size_t size, const string &option)
{
    char **itr = find(begin, (begin + size), option);
    if (itr != (begin + size) && ++itr != (begin + size))
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char **begin, int size, const string &option)
{
    return find(begin, begin + size, option) != (begin + size);
}

int main(int argc, char *argv[])
{
    string output;
    string input;
    string key = "nerfthis";

    bool decypher = cmdOptionExists(argv, argc, "-d");
    bool cypher = cmdOptionExists(argv, argc, "-c");

    if (decypher && cypher)
    {
        perror("Opção '-d' e '-c' não podem ser utilizadas juntas");
        exit(EXIT_FAILURE);
    }
    if (!decypher && !cypher)
    {
        perror("Faltando opção '-d' ou '-c");
        exit(EXIT_FAILURE);
    }

    if (cmdOptionExists(argv, argc, "-k"))
    {
        key = getCmdOption(argv, argc, "-k");
    }

    if (cypher)
    {
        getline(cin, input);
        output = Picypher::encode(input, key);
        output = crypt(output, key, 5);
        cout << output << endl;
    }

    if (decypher)
    {
        getline(cin, input);
        output = decrypt(input, key, 5);
        output = Picypher::decode(output, key);
        cout << output << endl;
    }

    return EXIT_SUCCESS;
}
