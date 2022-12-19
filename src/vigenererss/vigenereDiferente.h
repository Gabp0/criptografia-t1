#ifndef __VRBSS__
#define __VRBSS__

#include <string>
#define String std::string
#define VinDifSize 28

String decryptDiferente(String cypher, String key);
String cryptDiferente(String plain, String key);

#endif