#include <stdio.h>
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
        //test
        char userInput[100];
        scanf("%[^\n]%*c", userInput);
        char *separation = strtok(userInput, " ");
        char *userCommand[sizeof(userInput)];
        int index = 0;
        while (separation != NULL) {
            userCommand[index++] = separation;
            separation = strtok(NULL, " ");
        }


        if (strcmp(userCommand[0], "help") == 0) {
            nextLine(), help(), nextLine();;
            printf("[%s]", getcwd(userCommand, 100)), nextLine();
        } else if (strcmp(userCommand[0], "pwd") == 0) {
            printf("[%s]", getcwd(userCommand, 100)), nextLine();
        } else if (strcmp(userCommand[0], "exit") == 0) {
            exit(0);
        }


    }
    return 0;
}
