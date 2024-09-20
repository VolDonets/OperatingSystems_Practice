//
// Created by voldo on 20-Sep-24.
//

#include "string_ops.h"


void generateRandomString(char *randomString, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charsetSize = sizeof(charset) - 1;

    for (int i = 0; i < length; i++) {
        int key = rand() % charsetSize; // Pick a random index from the charset
        randomString[i] = charset[key]; // Assign the random character
    }

    randomString[length] = '\0'; // Null-terminate the string
}
