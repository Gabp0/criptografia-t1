#include "sbcspi.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <gmp.h>
#include <string>
#include <map>

using namespace std;

string SBCS314::encode(string plaintext, string key)
{
    string output;

    // inicializacoes
    plaintext = treatment(plaintext);
    initSBox(key);
    key = convertKey(key);
    initPip(stoi(key.substr(0, 2)));
    SBCS314::f_offset = stoi(key.substr(2, 5));

    for (size_t i = 0; i < ((plaintext.size() / BLOCK_SIZE) + 1); i++)
    { // separa em blocos de tamanho BLOCK_SIZE no maximo
        string sub = plaintext.substr(i * BLOCK_SIZE, BLOCK_SIZE);

        for (size_t j = 0; j < ITR_NUM; j++)
        {
            sub = roundSBox(sub);
            sub = roundOffset(j, sub, 1);
        }

        output += sub;
    }

    return output;
}

string SBCS314::decode(string cypheredtext, string key)
{
    string output;

    // inicializacoes
    initSBox(key);
    key = convertKey(key);
    initPip(stoi(key.substr(0, 2)));
    SBCS314::f_offset = stoi(key.substr(2, 5));

    for (size_t i = 0; i < ((cypheredtext.size() / BLOCK_SIZE) + 1); i++)
    { // separa em blocos de tamanho BLOCK_SIZE no maximo
        string sub = cypheredtext.substr(i * BLOCK_SIZE, BLOCK_SIZE);

        for (int j = ITR_NUM - 1; j >= 0; j--)
        { // ITR_NUM rodadas
            sub = roundOffset(j, sub, -1);
            sub = roundSBox(sub);
        }

        output += sub;
    }

    return output;
}

string SBCS314::roundOffset(int round, string sub, int s)
// faz o offset do bloco
{
    // inicializa lib gmp
    mpz_t offset;
    mpz_init(offset);
    mpz_t pip_pos;
    mpz_init(pip_pos);

    // calcula o offset da rodada atual
    mpz_set_ui(offset, SBCS314::f_offset);
    mpz_pow_ui(offset, offset, pow(2, round));
    mpz_mod_ui(pip_pos, offset, pip.size());
    unsigned int off_mod = mpz_get_ui(pip_pos);

    for (size_t k = 0; k < sub.size(); k++)
    { // faz o offset da letra
        int coff = pip[(off_mod + k) % pip.size()] - '0';
        sub[k] = offsetChar(sub[k], coff * s);
    }

    return sub;
}

string SBCS314::roundSBox(string sub)
// passa o bloco pela s-box
{
    for (size_t k = 0; k < sub.size(); k++)
    {
        sub[k] = SBCS314::sbox[sub[k]];
    }

    return sub;
}

void SBCS314::initSBox(string key)
// gera a sbox
{
    string ascii(key);

    for (string::size_type i = 0; i < ascii.size(); i++)
    { // remove chars repetidos da chave
        string::size_type j = i + 1;
        while (j < ascii.size())
        {
            if (ascii[i] == ascii[j])
            {
                ascii.erase(j, 1);
            }
            else
            {
                ++j;
            }
        }
    }

    for (size_t i = ASCII_L; i < (ASCII_U + 1); i++)
    { // completa o resto da tabela ascii
        if (key.find(i) == string::npos)
        {
            ascii += i;
        }
    }

    size_t asize = ASCII_U - ASCII_L + 1;
    for (size_t i = 0; i < asize; i++)
    { // gera o mapa
        SBCS314::sbox[ascii[i]] = ascii[gf[i]];
    }
}

string SBCS314::convertKey(string key)
// converte os valores em ascii dos caracteres da chave
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

void SBCS314::initPip(int pow)
// gera a potencia de pi
{
    char pip_char[PIP_MAX];

    mpz_t pi; // inicializa gmp (beeg pi)
    mpz_init(pi);
    mpz_set_str(pi, pi_str, 10);

    mpz_pow_ui(pi, pi, pow);       // pi^key[0:1]
    mpz_get_str(pip_char, 10, pi); // converte novamente para char

    SBCS314::pip = pip_char;
}

string SBCS314::treatment(string input)
// substitui characteres nao visiveis ou unicode
{
    for (char i : input)
    {
        if ((i > ASCII_U) || (i < ASCII_L))
        {
            replace(input.begin(), input.end(), i, 'X');
        }
    }

    return input;
}

char SBCS314::offsetChar(char c, int offset)
// offset dentro do range 22 a 126 da tabela ascii
{
    int out = c + offset;
    if (out > ASCII_U)
    {
        out = (out - (ASCII_U + 1)) + ASCII_L;
    }
    else if (out < ASCII_L)
    {
        out = (out - ASCII_L) + (ASCII_U + 1);
    }
    return out;
}
