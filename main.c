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
    char userCommand[100];
    char supportCd[3];
    printf("[%s]", getcwd(userCommand, 100)), nextLine();


    while (1) {
        printf("%s", "$ ");
        scanf("%[^\n]%*c", userCommand);
        strncpy(supportCd, userCommand, 2);
        char *changeDir = userCommand + 3;

        if (strcmp(userCommand, "help") == 0) {
            nextLine(), help(), nextLine();;
            printf("[%s]", getcwd(userCommand, 100)), nextLine();
        } else if (strcmp(supportCd, "cd") == 0) {
            if (strcmp(userCommand, "cd") == 0) {
                chdir(getenv("HOME"));
                printf("[%s]", getcwd(userCommand, 100)), nextLine();
            } else if (strcmp(changeDir, "~") == 0) {
                chdir(getenv("HOME"));
                printf("[%s]", getcwd(userCommand, 100)), nextLine();
            } else {
                chdir(changeDir);
                printf("[%s]", getcwd(userCommand, 100)), nextLine();
            }
        } else if (strcmp(userCommand, "pwd") == 0) {
            printf("[%s]", getcwd(userCommand, 100)), nextLine();
        } else if (strcmp(userCommand, "exit") == 0) {
            exit(0);
        } else {
            printf("Command '%s' not found", userCommand), nextLine();
        }
    }
    return 0;
}
