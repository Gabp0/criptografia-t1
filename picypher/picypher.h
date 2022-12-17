#ifndef __PICYPHER__
#define __PICYPHER__

#include <string>

using namespace std;

class Picypher
{
private:
    static const int BLOCK_SIZE = 128;
    static const int ITR_NUM = 16;
    static const int PIP_MAX = 39650;

    inline static const char *pi_str = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094";

    static string fill(string input);
    static string genPip(int pow);
    static char offsetChar(char c, int offset);

    // 18,446,744,073,709,551,615

    Picypher() {}

public:
    static string encode(string plaintext, string key);
    static string decode(string cypheredtext, string key);
};

#endif
