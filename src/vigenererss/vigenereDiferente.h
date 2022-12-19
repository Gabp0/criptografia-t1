#ifndef __VRBSS__
#define __VRBSS__

#include <string>
#define String std::string
#define VinSize 37

String decryptDiferente(String cypher, String key);
String cryptDiferente(String plain, String key);

#endif