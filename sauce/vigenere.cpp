#include "vigenere.h"
#include "common.h"
#include <string>
#include <iostream>


char cryptChar(int t, int k) {
	return common::toA((common::fromA(t) + common::fromA(k)) % VinSize);
}

char decryptChar(int t, int k) {
	k = common::fromA(k);
	t = common::fromA(t);

	int r;
	int c = k - t;
	if (c < 0)
		c = c * -1;

	r = c;
	if (k > t) {
		r = VinSize - k;
		r = r + t;
	}

	return common::toA(r % VinSize);
}

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

String crypt(String plain, String key, int n) {
	for (int i = 0; i < n; i++) {
		plain = crypt(plain, key);
	}
	return plain;
}

String cryptBizarro(String plain, String key) {
	plain.append("hs ahead");
	String subplain;
	for (int i = 0; i < 3; i++) {
		subplain = plain.substr(plain.size() - key.size(), key.size());
		plain = crypt(plain, key);
		key = crypt(key, subplain);
	}
	return plain;
}

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

String decrypt(String cypher, String key, int n) {
	for (int i = 0; i < n; i++) {
		cypher = decrypt(cypher, key);
	}
	return cypher;
}

String decryptBizarro(String cypher, String key) {
	String subcypher;
	cypher = decrypt(cypher, "rivjxlmw");
	cypher.erase(cypher.size() - 8, 8);
	return cypher;
}
