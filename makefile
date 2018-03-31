CC = gcc
CFLAGS = -Wall -g -std=c99

BIN = ./bin/
SRC = ./src/

program:
	$(CC) $(CFLAGS) $(SRC)HashTableAPI.c $(SRC)myFunctions.c $(SRC)FileReader.c $(SRC)main.c -Iinclude -o $(BIN)program

testing:
	$(CC) $(CFLAGS) $(SRC)HashTableAPI.c $(SRC)myFunctions.c $(SRC)testMain.c -Iinclude -o $(BIN)testing




cls:
	clear
