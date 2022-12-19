CC = g++
CPPFLAGS = -Wall -g

objs = vigenere.o common.o  

vigenere.o: vigenere.cpp vigenere.h common.h
common.o: common.cpp common.h

# remove arquivos temporários
clean:
	-rm -f $(objs) *~