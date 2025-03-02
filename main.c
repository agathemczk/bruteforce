//
// Created by agath on 02/03/2025.
//

#include <stdio.h>
#include <string.h>

#define PASSWORD "[Hello World !894?]"

char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";

void brute_force() {
    size_t length = strlen(PASSWORD);
    char found[length + 1];
    memset(found, 0, sizeof(found));
    size_t i, j;

    printf("Tentative de récupération du mot de passe...\n\n");

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

    printf("Mot de passe trouvé : %s\n", found);
}

int main() {
    brute_force();
    return 0;
}

