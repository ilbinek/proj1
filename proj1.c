#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 99;
const char *ERROR_INVALID_ARGUMENT = "";

void printAll();
void checkArgument(char *arg);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printAll();
    } else if (argc == 2) {
        checkArgument(argv[1]);

    } else {
        printf("%s", "Unknown arguments");
    }

    return 0;
}

void checkArgument(char *arg) {
    // Check if argument is only numbers
    for (int i = 0; i < strlen(arg); i++) {
        // If not, print error and exit
        if ((arg[i] >= '0' && arg[i] <= '9')) {
            fputs(ERROR_INVALID_ARGUMENT, stderr);
            exit(-1);
        }
    }
    return;
}

void printAll() {
    char str[MAX_LENGTH];
    // Loops through stdin and prints all lines
    while (fgets(str, MAX_LENGTH, stdin) != NULL) {
        printf("%s", str);
    }
    return;
}