#include "readfile.h"

void readfile(Node** list){

    //Creat FILE type
    FILE *inputFile;
    //Open file
    inputFile = fopen("numbers.txt", "r");

    if(inputFile == NULL){
        printf("Error while open file.\n");
        exit(EXIT_FAILURE);
    }
    
    //Scan file and add input into list
    int input;
    while(fscanf(inputFile, "%d%*c", &input)&& !feof(inputFile)){
        Add(list, input);
        if(*list == NULL) printf("%d\n", input);
    }  
    fclose(inputFile);  
}

