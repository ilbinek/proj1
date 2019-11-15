#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 101

void printAll();
void checkArgument(char *arg);

bool containsNumber(char str[MAX_LENGTH], char *nbr);

bool containsName(char *str, char *nbr);

bool isItThere(char str[MAX_LENGTH], char c, int *pos);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // If no arguments submitted, prints all
        printAll();
    } else if (argc == 2) {
        checkArgument(argv[1]);
        bool found = false;
        char name[MAX_LENGTH];
        char nbr[MAX_LENGTH];
        // Check for all names
        while (fgets(name, MAX_LENGTH, stdin) != NULL) {
            // Checks for all numbers
            if (fgets(nbr, MAX_LENGTH, stdin) != NULL) {
                // Check if we should print this contact
                if (containsNumber(nbr, argv[1]) || containsName(name, argv[1])) {
                    printf("%.*s, %s", (int)strlen(name) - 1, name, nbr);
                    found = true;
                }
            } else {
                printf("%s", "NO NUMBER FOUND");
            }
        }
        // Print something if nothing was found
        if (!found) {
            // If no contact found, prints all
            printf("%s", "Not found");
        }
    } else {
        fputs("UNKNOWN ARGUMENTS\n", stderr);
    }
    printf("\n");
    return 0;
}

// finds out if the number is in the next part of the contact
bool isItThere(char str[MAX_LENGTH], char c, int *pos) {
    int size = (int)strlen(str);
    // Check for all chars that are left
    for (int i = *pos; i < size; i++) {
        // Check if
        switch (c) {
            case '1':
                return false;

            case '2':
                if (str[i] == 'a' || str[i] == 'A' || str[i] == 'b' || str[i] == 'B' || str[i] == 'c' || str[i] == 'C') {
                *pos = i + 1;
                    return true;
                }
                break;

            case '3':
                if (str[i] == 'd' || str[i] == 'D' || str[i] == 'e' || str[i] == 'E' || str[i] == 'f' || str[i] == 'F') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '4':
                if (str[i] == 'g' || str[i] == 'G' || str[i] == 'h' || str[i] == 'H' || str[i] == 'i' || str[i] == 'I') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '5':
                if (str[i] == 'j' || str[i] == 'J' || str[i] == 'k' || str[i] == 'K' || str[i] == 'l' || str[i] == 'L') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '6':
                if (str[i] == 'm' || str[i] == 'M' || str[i] == 'n' || str[i] == 'N' || str[i] == 'o' || str[i] == 'O') {
                    *pos = i;
                    return true;
                }
                break;

            case '7':
                if (str[i] == 'p' || str[i] == 'P' || str[i] == 'q' || str[i] == 'Q' || str[i] == 'r' || str[i] == 'R' || str[i] == 's' || str[i] == 'S') {
                    *pos = i;
                    return true;
                }
                break;

            case '8':
                if (str[i] == 't' || str[i] == 'T' || str[i] == 'u' || str[i] == 'U' || str[i] == 'v' || str[i] == 'V') {
                    *pos = i;
                    return true;
                }
                break;

            case '9':
                if (str[i] == 'w' || str[i] == 'W' || str[i] == 'x' || str[i] == 'X' || str[i] == 'y' || str[i] == 'Y' || str[i] == 'z' || str[i] == 'Z') {
                    *pos = i;
                    return true;
                }
                break;

            case '0':
                if (str[i] == '+') {
                    *pos = i;
                    return true;
                }
                break;

            default:
                // Go on
                break;
        }
    }
    return false;
}

bool containsName(char str[MAX_LENGTH], char *nbr) {
    // Define what position are we starting the search
    int pos = 0;
    int size = (int)strlen(nbr);
    for (int i = 0; i < size; i++) {
        // Checks if there's a char after our previous
        if (!isItThere(str, nbr[i], &pos)) {
            // If not, returns false
            return false;
        }
    }
    // Otherwise returns true
    return true;
}

bool containsNumber(char *str, char *nbr) {
    // Does it contain exact match
    return strstr(str, nbr) != NULL;
}

void checkArgument(char *arg) {
    // Check if argument is only numbers
    int size = (int)strlen(arg);
    for (int i = 0; i < size; i++) {
        // If not, print error and exit
        if (!(arg[i] >= '0' && arg[i] <= '9')) {
            fputs("INVALID ARGUMENT\n", stderr);
            exit(-1);
        }
    }
}

// Prints all contacts
void printAll() {
    char str[MAX_LENGTH];
    char nbr[MAX_LENGTH];
    // Loops through stdin and prints all lines
    while (fgets(str, MAX_LENGTH, stdin) != NULL && fgets(nbr, MAX_LENGTH, stdin)) {
        printf("%.*s, %s", (int)strlen(str) - 1, str, nbr);
    }
    printf("\n");
}