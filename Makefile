CC = gcc
CFLAGS = -ansi -Wall -pedantic
INCLUDES = funcoes.c
SRC =  main.c 


all: proj1

proj1: $(INCLUDES) $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o proj1
