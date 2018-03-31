
#include "FileReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void loadFile(char * filename, HTable* dictonary)
{
    FILE * file;
    file = fopen(filename, "r");
    printf("%s", filename);
    if(file == NULL)
    {
    printf("Error loading file(s)\n");
    exit(1);
    }
    
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

        insertData(dictonary, list[index],list[index]);
        index++;
    }
    
    fclose(file);

}