#include "common.h"

int common::fromA(char t) {
	if(t >= 97)
	return t - 97;
	return t - 65;
}

char common::toA(int t) {
	return t + 97;
}
