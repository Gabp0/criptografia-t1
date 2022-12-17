#include <iostream>
#include "common.h"
#include "vigenere.h"
#include <string>

#define String std::string 
#define out std::cout 
#define nl std::endl

int main()
{
	String key = "nerfthis";
	String text = "there is no reasonable excuse for not doing so in addition to the expected disruptions there are going to be greater and greater expectations on a massive scale The Star Wars cast seems to be getting ready for a full-scale assault in the months ahead";
	String cypher;

	int i = 0;
	int s = 8;

	out << key << nl << nl;
	out << text << nl << nl;

	cypher = crypt(text, key, 3);

	out << cypher << nl << nl;

	cypher = decrypt(cypher, key, 3);

	out << cypher << nl << nl;

	return 0;
}
