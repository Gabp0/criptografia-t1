#ifndef __PICYPHER__
#define __PICYPHER__

#include <string>
#include <map>

using namespace std;

class Picypher
{
private:
    static const int BLOCK_SIZE = 128;
    static const int KEY_SIZE = 7;
    static const int ITR_NUM = 16;
    static const int PIP_MAX = 39650;

    inline static const char *pi_str = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094";

    inline static int gf[] = {0, 1, 48, 32, 24, 5, 16, 68, 12, 74, 10, 26, 8, 22, 34, 15, 6, 28, 37, 19, 20, 86, 13, 62, 4, 25, 11, 88, 17, 59, 30, 46, 3, 72, 14, 35, 66, 18, 38, 39, 40, 51, 43, 42, 54, 45, 31, 93, 2, 64, 50, 41, 53, 52, 44, 55, 56, 57, 77, 29, 60, 81, 23, 92, 49, 65, 36, 78, 7, 84, 70, 91, 33, 82, 9, 75, 76, 58, 67, 89, 80, 61, 73, 87, 69, 85, 21, 83, 27, 79, 90, 71, 63, 47, 94};

    inline static map<char, char> sbox;

    static string treatment(string input);
    static void genSBox(string key);
    static string genPip(int pow);
    static char offsetChar(char c, int offset);
    static string convertKey(string key);

    Picypher() {}

public:
    static string encode(string plaintext, string key);
    static string decode(string cypheredtext, string key);
};

#endif
