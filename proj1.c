#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX_LENGTH = 99;
const char *ERROR_INVALID_ARGUMENT = "INVALID ARGUMENT";
const char *ERROR_UNKNOWN_ARGUMENTS = "UNKNOWN ARGUMENTS";
const char *NOT_FOUND = "Not found";

void printAll();
void checkArgument(char *arg);

bool containsNumber(char str[99], char *nbr);

bool containsName(char str[99], char *nbr);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printAll();
    } else if (argc == 2) {
        checkArgument(argv[1]);
        bool found = false;
        char str[MAX_LENGTH];
        while (fgets(str, MAX_LENGTH, stdin) != NULL) {
            // Check if we should print this contact
            if (containsNumber(str, argv[1]) || containsName(str, argv[1])) {
                printf("%s", str);
                found = true;
            }
        }

        // Print something if nothing was found
        if (!found) {
            printf("%s", NOT_FOUND);
        }
    } else {
        fputs(ERROR_UNKNOWN_ARGUMENTS, stderr);
    }
    return 0;
}

bool containsName(char str[99], char *nbr) {
    // Creating returning variable
    
    bool ret = false;
    return 0;
}

bool containsNumber(char str[99], char *nbr) {
    // Does it contain exact match
    bool ret = strstr(str, nbr);
    return ret;
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