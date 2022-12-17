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
	String text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean sit amet purus sagittis eros sollicitudin euismod. Proin sit amet magna facilisis, mollis leo malesuada, feugiat nibh. Suspendisse hendrerit semper odio sed feugiat. In vel faucibus dui, id rhoncus magna. Sed fermentum, magna non hendrerit accumsan, est quam ultrices purus, ac pulvinar turpis ipsum sit amet ante. Maecenas justo massa, bibendum sed hendrerit nec, imperdiet sit amet nisl. Curabitur semper nec nunc at faucibus. Suspendisse semper tincidunt eros, non imperdiet augue ullamcorper non. Aliquam orci augue, posuere sit amet consectetur nec, pharetra in lorem. Nam semper tempus mauris eu hendrerit. Vestibulum at quam sollicitudin dolor ornare placerat in sed velit. Phasellus vitae enim lacus.";

	
	String cypher;

	int i = 0;
	int s = 8;

	out << key << nl << nl;
	out << text << nl << nl;

	

	cypher = cryptBizarro(text, key);

	out << cypher << nl << nl;

	cypher = decryptBizarro(cypher, key);

	

	out << cypher << nl << nl;

	return 0;
}
