#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 102  // Maximum length of characters, that program can handle

void printAll();    // Prints everything that get's into stdin
void checkArgument(char *arg);  // Check if arguments that was provided isn't in unsupported format

bool
containsNumber(char str[MAX_LENGTH], char *nbr);   // Checks if the number that was provided is in the contact's number

bool containsName(char str[MAX_LENGTH], char *nbr);    // Checks if the number provided is in the contact's name

bool isItThere(char str[MAX_LENGTH], char c,
               int *pos); // Checks if desired character that corresponds to number is in the next part of string provided

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // If no arguments submitted, prints all
        printAll();
    } else if (argc == 2) {
        // Check argument
        checkArgument(argv[1]);
        bool found = false;
        // Defines two strings that will hold name and number of desired contact
        char name[MAX_LENGTH];
        char nbr[MAX_LENGTH];
        // Check for all names
        while (fgets(name, MAX_LENGTH, stdin) != NULL) {
            // Checks for all numbers
            if (fgets(nbr, MAX_LENGTH, stdin) != NULL) {
                // Check if we should print this contact
                if (containsNumber(nbr, argv[1]) || containsName(name, argv[1])) {
                    // Print contact with desired formatting
                    printf("%.*s, %s", (int) strlen(name) - 1, name, nbr);
                    found = true;
                }
            } else {
                // Print a message when no number was found
                printf("%s", "NO NUMBER FOUND");
            }
        }
        // Print something if nothing was found
        if (!found) {
            // If no contact found, prints all
            printf("%s", "Not found");
        }
    } else {
        // Prints error when we have more arguments
        fputs("UNKNOWN ARGUMENTS\n", stderr);
    }
    printf("\n");
    return 0;
}

// Checks if desired character that corresponds to number is in the next part of string provided
bool isItThere(char str[MAX_LENGTH], char c, int *pos) {
    int size = (int) strlen(str);
    // Check for all characters that are left
    for (int i = *pos; i < size; i++) {
        /* Check if current character corresponds to desired number
         * If so, set value of position to the next character
         * and return true, that a character was found
        */
        switch (c) {
            case '1':
                if (str[i] == '1') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '2':
                if (str[i] == 'a' || str[i] == 'A' || str[i] == 'b' || str[i] == 'B' || str[i] == 'c' ||
                    str[i] == 'C' || str[i] == '2') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '3':
                if (str[i] == 'd' || str[i] == 'D' || str[i] == 'e' || str[i] == 'E' || str[i] == 'f' ||
                    str[i] == 'F' || str[i] == '3') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '4':
                if (str[i] == 'g' || str[i] == 'G' || str[i] == 'h' || str[i] == 'H' || str[i] == 'i' ||
                    str[i] == 'I' || str[i] == '4') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '5':
                if (str[i] == 'j' || str[i] == 'J' || str[i] == 'k' || str[i] == 'K' || str[i] == 'l' ||
                    str[i] == 'L' || str[i] == '5') {
                    *pos = i + 1;
                    return true;
                }
                break;

            case '6':
                if (str[i] == 'm' || str[i] == 'M' || str[i] == 'n' || str[i] == 'N' || str[i] == 'o' ||
                    str[i] == 'O' || str[i] == '6') {
                    *pos = i;
                    return true;
                }
                break;

            case '7':
                if (str[i] == 'p' || str[i] == 'P' || str[i] == 'q' || str[i] == 'Q' || str[i] == 'r' ||
                    str[i] == 'R' || str[i] == 's' || str[i] == 'S' || str[i] == '7') {
                    *pos = i;
                    return true;
                }
                break;

            case '8':
                if (str[i] == 't' || str[i] == 'T' || str[i] == 'u' || str[i] == 'U' || str[i] == 'v' ||
                    str[i] == 'V' || str[i] == '8') {
                    *pos = i;
                    return true;
                }
                break;

            case '9':
                if (str[i] == 'w' || str[i] == 'W' || str[i] == 'x' || str[i] == 'X' || str[i] == 'y' ||
                    str[i] == 'Y' || str[i] == 'z' || str[i] == 'Z' || str[i] == '9') {
                    *pos = i;
                    return true;
                }
                break;

            case '0':
                if (str[i] == '+' || str[i] == '0') {
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
    // Get size of our string
    int size = (int) strlen(nbr);
    // Iterate through string
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

bool containsNumber(char str[MAX_LENGTH], char *nbr) {
    // Define what position are we starting the search
    int pos = 0;
    // Get size of our string
    int size = (int) strlen(nbr);
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

void checkArgument(char *arg) {
    // Check if argument is only numbers
    int size = (int) strlen(arg);
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
        printf("%.*s, %s", (int) strlen(str) - 1, str, nbr);
    }
    printf("\n");
}