# Makefile
# feito por Gabriel Pontarolo

CC = g++
CPPFLAGS = -Wall -g
LDLIBS = -lm -lgmp

VPATH = src:src/sbcspi:src/vigenererss

objs = main.o sbcspi.o vigenere.o common.o

TARGET = rgps

all: $(TARGET)

# ligacao
$(TARGET): $(objs)
	$(CC) $(CPPFLAGS) $(LDLIBS) $(objs) -o rgps

# compilacao
main.o: main.cpp sbcspi.h vigenere.h
sbcspi.o: sbcspi.cpp sbcspi.h
vigenere.o: vigenere.cpp vigenere.h common.h
common.o: common.cpp common.h

clean:
	-rm -f $(objs) *~

purge: clean
	-rm -f rgps

