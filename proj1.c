#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int MAX_LENGTH = 99;

void printAll();
bool readLine(char *str);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printAll();
    } else if (argc == 2) {
        
    } else {
        printf("%s", "Unknown arguments");
    }

    return 0;
}

void printAll() {
    char str[MAX_LENGTH];
    while (fgets(str, MAX_LENGTH, stdin) != NULL) {
        printf("%s", str);
    }
}

bool readLine(char *str) {

}