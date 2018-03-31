#include "FileReader.h"
#include "HashTableAPI.h"
#include "MyFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char **argv){
	char userInput[100];
	int index = 0;
	char ** myList = malloc (sizeof(char*) * 200);
	for (int i = 0; i < 200; i++)
    {
        myList[i]= malloc(sizeof(char *));
    }
    /**create hash table and load in the Dictionary*/
	HTable* dictonary = createTable(200,&hashFunction,&removeWord,&printWord);
	loadFile(argv [1], dictonary);
	/** loop until the user quits (5)*/
	while (1==1){
		/** menu display**/
		printf("\nWelcome to the Dictonary Program\n" );
		printf("1) Add a word to the Dictonary\n");
		printf("2) Remove a word to the Dictonary\n");
		printf("3) Spell Check a file\n");
		printf("4) Show Dictionary Words\n");
		printf("5) Quit\n");
		printf("Input: ");
		/**get user input and take away the \n*/
		fgets(userInput,100,stdin);
		strtok(userInput, "\n");
		printf("\n");
		/** insert a word to the dictionary*/
		if (strcmp(userInput,"1") == 0){
			printf("Enter the Word you wish to add:\n");

			fgets(myList[index],200,stdin);
			strtok(myList[index], "\n");
			/** convert the word to lower case*/
		    for(int i = 0; i< strlen(myList[index])-1;i++){
        		myList[index][i]= tolower(myList[index][i]);
    		}
    		/** insert the data to the table*/
			insertData(dictonary, myList[index],myList[index]);
			printf("%s added to Dictionary\n",myList[index]);
			//printFunction(dictonary);
		}
		/** remove a word*/
		else if (strcmp(userInput,"2") == 0){
			
			printf("Enter the Word you wish to remove:\n");
			fgets(myList[index],200,stdin);
			/**removes the \n*/
			strtok(myList[index], "\n");
			
		    for(int i = 0; i< strlen(myList[index])-1;i++){
        		myList[index][i]= tolower(myList[index][i]);
    		}
    		/** removes the word*/
			removeData(dictonary, myList[index]);
		}
		/**spell check*/
		else if (strcmp(userInput,"3") == 0){
			char* lookUp;
			int counter = 0;
			int incorrect = 0;
			char fileName[50];

			/** get the file to be used as userFile*/
			printf("File to be processed by Spell Check:");
			fgets(fileName,100,stdin);
			strtok(fileName, "\n");
			FILE * file;
		    file = fopen(fileName, "r");
		    /** if the file doesnt exist exit*/
		    if(file == NULL)
		    {
		    	printf("Error loading file(s)\n");
		    	
		    }

		    else{
		    	/**create the list that the userFile words will go into*/
				int index = 0;
			    char ** list = malloc (sizeof(char*) * 200);

			    for (int i = 0; i < 200; i++)
			    {
			        list[i]= malloc(sizeof(char *));
			    }

			    
			    while(fgets(list[index],200,file) != NULL)
			    {    
			        strtok(list[index],"\n");
			        for(int i = 0; i< strlen(list[index]);i++){
			            list[index][i]= tolower(list[index][i]);
			        }

			        index++;
			    }
			    printf("\n");
			    /** loop through each word and check with the dictionary*/
			    for (int i = 0; i< index; i++){
			    	lookUp = lookupData(dictonary, list[i]);
			    	if(lookUp == NULL){
			    		printf("%s wasn't found in the Dictionary\n",list[i]);
			    		incorrect++;
			    	}
			    	else{
			    		counter++;
			    	}
				}
				printf("\n");
				printf("Summary:\n");
				printf("%d words are spelt correctly\n", counter);
				printf("%d words are spelt incorrectly\n", incorrect);
				fclose(file);
			}
		}
		/** print the HashTable*/
		else if (strcmp(userInput,"4") == 0){
			printFunction(dictonary);
		}
		/**quit program, distroy hashTable*/
		else if (strcmp(userInput,"5") == 0){
			printf("****ENDING PROGRAM****\n");
			destroyTable(dictonary);
			break;
		}
	}

	return 0;
}
