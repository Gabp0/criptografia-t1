#include "common.h"

int common::fromA(char t) {
	return t - 32;
}

char common::toA(int t) {
	return t + 32;
}

int common::fromABizarro(char t) {
	switch (t) {
	case ' ':
		return 26;
		break;
	case '.':
		return 27;
		break;
	default:
		if (t >= 97)
			return t - 97;
		return t - 65;
	}
}

char common::toABizarro(int t) {
	switch (t) {
	case 26:
		return ' ';
		break;
	case 27:
		return '.';
		break;
	default:
		if (t <= 97)
			return t + 97;
		return t + 65;
	}
}