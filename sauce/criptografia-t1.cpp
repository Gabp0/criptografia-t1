#include <iostream>
#include "common.h"
#include "vigenere.h"

int main()
{
	char key[10000] = "nerfthis";
	char text[] = "there is no reasonable excuse for not doing so in addition to the expected disruptions there are going to be greater and greater expectations on a massive scale The Star Wars cast seems to be getting ready for a full-scale assault in the months ahead";
	char cypher[10000];
	char hambur[10000];

	int i = 0;
	int s = 8;

	for (; text[i]; i++) {
		if (text[i] != 32) {
			cypher[s-8] = crypt(text[i], key[s-8]);
			key[s] = text[i];
			s++;
		}
	}
	cypher[s-8] = '\0';

	std::cout << text << std::endl << std::endl << key << std::endl << std::endl;
	std::cout << cypher << std::endl << std::endl;
	i = 0;
	s = 8;
	for (; cypher[i]; i++, s++) {
		hambur[i] = decrypt(cypher[i], key[i]);
		key[s] = hambur[i];
	}
	hambur[i] = '\0';
	std::cout << hambur;
	return 0;
}
