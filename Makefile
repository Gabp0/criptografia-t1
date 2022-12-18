all:
	gcc main.cpp sauce/vigenere.cpp sauce/common.cpp picypher/picypher.cpp -lstdc++ -lgmp -lm -o rgps 