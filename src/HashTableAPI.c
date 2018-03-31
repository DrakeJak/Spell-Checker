#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableAPI.h"
#include "MyFunctions.h"

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, char* key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted)){
	HTable* tempPtr = malloc(sizeof(HTable));
	if(tempPtr != NULL){
		tempPtr -> table = malloc(sizeof(Node*)*size);
		tempPtr -> size = size;
		tempPtr->count = 0;
		tempPtr -> destroyData = destroyData;
		tempPtr->hashFunction = hashFunction;
		tempPtr->printNode = printNode;
		
	}
	return tempPtr;
}

Node *createNode(char* key, void *data){
	Node* n = malloc(sizeof(Node));
	n -> next = NULL;
	n -> data = data;
	n -> key = key;
	return n;
}

void destroyTable(HTable *hashTable){
	int index = 0;
	while (index != hashTable -> size-1){
		free(hashTable ->table[index]);
		hashTable -> table[index] = NULL;
		index++;
	}
	free(hashTable -> table);
	hashTable -> table = NULL;
	free(hashTable);
	hashTable = NULL;
}

void insertData(HTable *hashTable, char* key, void *data){
	Node* n = createNode(key,data);

	int index;
	index = hashTable -> hashFunction(hashTable -> size, key);

	while (hashTable -> table[index] != NULL){
		if (strcmp(hashTable -> table [index] -> key,key) ==0){
			break;
		}

		else{
			index = (index+1) % hashTable -> size;
		}

	}

	hashTable->table [index] = n;

}
void removeData(HTable *hashTable, char* key){
	if (lookupData(hashTable,key)!= NULL){
		int index;
		index = hashTable -> hashFunction (hashTable->size, key);
		while (strcmp(hashTable -> table [index] -> key,key) !=0){
			index = (index+1) % hashTable ->size;
		}
		hashTable->table[index] -> key="*";
		hashTable->table[index] -> data ="*";
		//hashTable->table[index] =NULL;
	}
	
}
void *lookupData(HTable *hashTable, char* key){
	int index;
	index = hashTable->hashFunction(hashTable -> size,key);
	while(hashTable -> table[index] != NULL){
		if (strcmp(hashTable->table[index]->key, key) ==0){
			return hashTable -> table[index] ->data;
			
		}
		index++;
		index = index % hashTable -> size;
	}
	return NULL;
}
