#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableAPI.h"
#include "MyFunctions.h"


int hashFunction (size_t size, char* key){
	int index = 0;
	for (int i = 0; i< strlen(key); i++){
		index = index +(int) key[i];
	}
	return index % size;
}

void printFunction(HTable* hashTable){
	int index = 0;
	while (index != hashTable-> size -1){
		if (hashTable ->table[index] !=NULL){
			if (strcmp(hashTable ->table[index]->data,"*")){
				printf("%d:%s:%s\n", index, hashTable -> table[index]->key, (char*) hashTable -> table[index]->data);
			}
		}

		index++;
	}
}

void removeWord(void* data){
	free(data);
	data = NULL;
}

void printWord(void* data){
	printf("%s\n", (char*)data);
}

