#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void nextLine() {
    printf("\n");
}

void help() {
    printf("*** MicroShell SOP ***"), nextLine();
    printf("Author: Jakub Olek"), nextLine();
    printf("Functions: "), nextLine();
    printf("help"), nextLine();
    printf("cd"), nextLine();
    printf("path"), nextLine();
    printf("fork"), nextLine();
    printf("exit"), nextLine();
}


int main() {


    while (1) {
        char userInput[100];
        printf("[%s:%s]\n$ ", getenv("USER"), getcwd(userInput, 100));
        scanf(" %[^\n]%*c", userInput);

        char *separation = strtok(userInput, " ");
        char *userCommand[sizeof(userInput)];
        int index = 0;
        while (separation != NULL) {
            userCommand[index++] = separation;
            separation = strtok(NULL, " ");
        }
        if (strcmp(userCommand[0], "help") == 0) {
            nextLine(), help(), nextLine();;
        } else if (strcmp(userCommand[0], "cd") == 0) {
            if (strcmp(userCommand[1], "~") == 0) {
                chdir(getenv("HOME"));
            } else if (index <= 1) {
                chdir(getenv("HOME"));
            } else if (chdir(userCommand[1]) == 0) {
            } else if (chdir(userCommand[1]) != 0) {
                printf("cd: %s: No such file or directory", userCommand[1]), nextLine();
            }

        } else if (strcmp(userCommand[0], "pwd") == 0) {
            printf("%s", getcwd(userInput, 100)), nextLine();
        } else if (strcmp(userCommand[0], "exit") == 0) {
            exit(0);
        }


    }
    return 0;
}
