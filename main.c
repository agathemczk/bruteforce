//
// Created by agath on 02/03/2025.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12
char PASSWORD[PASSWORD_LENGTH + 1];

//#define PASSWORD "[Hello World !894?]"

char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";

void generate_random_password() {
    size_t charset_length = strlen(charset);
    srand(time(NULL));
    for (size_t i = 0; i < PASSWORD_LENGTH; i++) {
        PASSWORD[i] = charset[rand() % charset_length];
    }
    PASSWORD[PASSWORD_LENGTH] = '\0';
}

void brute_force() {
    size_t length = strlen(PASSWORD);
    char found[length + 1];
    memset(found, 0, sizeof(found));
    size_t i, j;

    printf("Trying to get the password...\n\n");

    for (i = 0; i < length; i++) {
        for (j = 0; j < strlen(charset); j++) {
            printf("%s%c\n", found, charset[j]);
            if (PASSWORD[i] == charset[j]) {
                found[i] = charset[j];
                found[i + 1] = '\0';
                printf("%s\n", found);
                break;
            }
        }
    }

    printf("Password : %s\n", found);
}

int main() {
    generate_random_password();
    printf("Generated password : %s\n", PASSWORD);
    brute_force();
    return 0;
}

