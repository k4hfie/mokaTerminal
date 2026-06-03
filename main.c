#include <stdio.h>
#include <string.h>
#include "command.c"

#define USERNAME_SIZE 50
#define INPUT_SIZE 100


int getInput(char *input, int size){
    if(fgets(input, size, stdin) == NULL){
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    return 0;
}

void setUsername(char *name, int size, int *status){
    printf("Enter Username: "); 
    if(getInput(name, size)){
        myExit(status);
    }
}

void displayTitle(){
    myClear();
    printf("Welcome to mokaShell!\n");
}

void terminalPrompt(const char *username){
    printf("%s@mokaShell:~$ ", username);
}

void terminalInteraction(int *status){
    char input[INPUT_SIZE];
    if(getInput(input, sizeof(input))){
        myExit(status);
    }

    //implement parsing with strtok

    if (strcmp(input, "help") == 0){
        myHelp();
    }

    else if (strcmp(input, "clear") == 0){
        myClear();
    }

    else if (strcmp(input, "exit") == 0){
        myExit(status);
    }

    else{
        printf("\nCommand not Found!\n\n");
    }
}

int main(void){
    int status = 1;
    char username[USERNAME_SIZE];

    displayTitle();
    setUsername(username, sizeof(username), &status);
    myClear();

    while (status == 1){
        terminalPrompt(username);
        terminalInteraction(&status);
    }
}