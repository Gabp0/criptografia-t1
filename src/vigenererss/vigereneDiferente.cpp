#include "vigenereDiferente.h"
#include "common.h"
#include <string>
#include <iostream>

using namespace commonVigenereDiferente;

//Criptografa um char a partir de uma chave
char cryptChar(int t, int k) {
	return toAscii((fromAscii(t) + fromAscii(k)) % VinSize);
}

//Decriptografa um char a partir de uma chave
char decryptChar(int t, int k) {
	k = fromAscii(k);
	t = fromAscii(t);

	int r;
	int c = k - t;
	if (c < 0)
		c = c * -1;

	r = c;
	if (k > t) {
		r = VinSize - k;
		r = r + t;
	}

	return toAscii(r % VinSize);
}

//Criptografa uma string a partir de uma chave
String crypt(String plain, String key) {
	key.append(plain);
	String s;
	for (char t : plain) {
		int i = 0;
		s += cryptChar(t, key[i]);
		i++;
	}
	return s;
}

//Roda o algoritmo n vezes
String crypt(String plain, String key, int n) {
	for (int i = 0; i < n; i++) {
		plain = crypt(plain, key);
	}
	return plain;
}

//Decriptografa uma string a partir de uma chave
String decrypt(String cypher, String key) {
	String s;
	char r;
	for (char t : cypher) {
		int i = 0;
		r = decryptChar(t, key[i]);
		s += r;
		key += r;
		i++;
	}
	return s;
}

String cryptDiferente(String plain, String key) {
	plain.append("hs ahead");
	String subplain;
	for (int i = 0; i < 3; i++) {
		subplain = plain.substr(plain.size() - key.size(), key.size());
		plain = crypt(plain, key);
		key = crypt(key, subplain);
	}
	return plain;
}


String decryptDiferente(String cypher, String key) {
	String subcypher;
	cypher = decrypt(cypher, "rivjxlmw");
	cypher.erase(cypher.size() - 8, 8);
	return cypher;
}