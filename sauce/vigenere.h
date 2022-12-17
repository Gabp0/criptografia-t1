#pragma once
#include <string>
#define String std::string
#define VinSize 28

char cryptChar(int t, int k);
char decryptChar(int t, int k);
String crypt(String plain, String key);
String decrypt(String chyper, String key);
String crypt(String plain, String key, int n);
String decrypt(String chyper, String key, int n);
String cryptBizarro(String plain, String key);
String decryptBizarro(String chyper, String key);