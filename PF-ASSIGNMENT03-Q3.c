#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validateEmail(char *email) {
    int atCount = 0, dotCount = 0;
    int i = 0;

    if (email[0] == '\0') {
        return 0;
    }

    while (email[i] != '\0') {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
        i++;
    }

    return (atCount == 1 && dotCount > 0 && dotCount >= atCount);
}

int main() {
    char *email;
    int length;
    char emailAddress[100];

    printf("Enter your email address: ");

    scanf("%s", &emailAddress);
    length = strlen(emailAddress);

    email = (char *)malloc((length + 1) * sizeof(char));

    strcpy(email, emailAddress);

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}