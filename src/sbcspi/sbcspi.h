
#ifndef __SBCSPI__
#define __SBCSPI__

#include <string>
#include <map>

using namespace std;

class SBCS314
{
private:
    static const int BLOCK_SIZE = 128; // tamanho maximo do bloco de texto
    static const int KEY_SIZE = 7;     // tamanho minimo da chave
    static const int ITR_NUM = 16;     // numero de iteracoes (24 ITR -> 10 segundos)
    static const int PIP_MAX = 39650;  // numero maximo de characteres do pip
    static const int ASCII_L = 32;     // lower bound dos caracteres visiveis da ascii
    static const int ASCII_U = 126;    // upper bound dos caracteres visiveis da ascii

    // aproximacao dos digitos de pi ate a 400 casa decimal (fonte wikipedia)
    inline static const char *pi_str = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094";

    // inverso multiplicativo do GF(95)
    inline static int gf[] = {0, 1, 48, 32, 24, 5, 16, 68, 12, 74, 10, 26, 8, 22, 34, 15, 6, 28, 37, 19, 20, 86, 13, 62, 4, 25, 11, 88, 17, 59, 30, 46, 3, 72, 14, 35, 66, 18, 38, 39, 40, 51, 43, 42, 54, 45, 31, 93, 2, 64, 50, 41, 53, 52, 44, 55, 56, 57, 77, 29, 60, 81, 23, 92, 49, 65, 36, 78, 7, 84, 70, 91, 33, 82, 9, 75, 76, 58, 67, 89, 80, 61, 73, 87, 69, 85, 21, 83, 27, 79, 90, 71, 63, 47, 94};

    inline static map<char, char> sbox; // substitution box
    inline static string pip;           // potencia de pi
    inline static int f_offset;         // offset inicial na potencia de pi

    // funcoes auxiliares
    static string treatment(string input);
    static void initSBox(string key);
    static void initPip(int pow);
    static string roundOffset(int round, string sub, int s);
    static string roundSBox(string sub);
    static char offsetChar(char c, int offset);
    static string convertKey(string key);

    SBCS314() {}

public:
    static string encode(string plaintext, string key);
    static string decode(string cypheredtext, string key);
};

#endif
