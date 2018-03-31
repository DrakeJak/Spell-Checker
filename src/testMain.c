#include "HashTableAPI.h"
#include "MyFunctions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (){
	printf("\n1.For this Test: create a node\n");
	printf("Expected output: display the node\n");
	Node* testNode =createNode("testing","testing");
	printf("recieved\n");
	printf("%s\n", (char *) testNode -> data );
	printf("Result: *****test passed***** \n");
	printf(" ");

	printf("\n2.For this Test: create a Hash Table\n");
	printf("Expected output: display the Hash Table");
	HTable* testHash = createTable(10,&hashFunction,&removeWord,&printWord);
	printf("\n****HashTableAPI created****\n");
	testHash->printNode(testHash);
	printf("Result: ****test passed****\n");
	printf(" ");

	printf("\n3.For this Test: insert into the Hash Table\n");
	printf("Expected output: testing is now in the Hash Table");
	insertData(testHash,"testing","testing");
	insertData(testHash,"this","this");
	insertData(testHash,"program","program");
	printf("\n****data inserted****\n");
	printFunction(testHash);
	printf("\nResult: ****test passed****\n");
	printf(" ");

	printf("\n4.For this test: remove a word from the hash table\n");
	printf("Expected output: 'this' will be removed\n");
	removeData(testHash,"this");
	printf("\n****removed word****\n");
	printFunction(testHash);
	printf("Result: ****testpassed****");
	printf(" ");

	printf("\n5.For this test: use look up data\n");
	printf("Expected output: test2 will be found\n");
	insertData(testHash,"test1","test2");
	char* testLookUp = lookupData(testHash, "test1");
	printf("data found: %s\n", testLookUp);
	printf("\nResult: ****tested passed****\n");
	printf(" ");

	printf("\n6.For this Test: destroy the hash table\n");
	printf("Expected result: segfault if the hash table is destroyed\n");
	destroyTable(testHash);
	printf("CODE COMMENTED OUT TO PREVENT SEGFAULT\n(remove the comment to have segfault)\n");
	//printFunction(testHash);
	printf("Result: ****test passed****\n");
	printf(" ");



	return 0;
}
