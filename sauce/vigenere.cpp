#include "vigenere.h"
#include "common.h"

char crypt(int t, int k) {
	return common::toA((common::fromA(t) + common::fromA(k))%26);
}

char decrypt(int t, int k) {
	k = common::fromA(k);
	t = common::fromA(t);
	
	int r;
	int c = k - t;
	if (c < 0)
		c = c * -1;

	r = c;
	if (k > t) {
		r = 26 - k;
		r = r + t;
	}

	return common::toA(r%26);
}
