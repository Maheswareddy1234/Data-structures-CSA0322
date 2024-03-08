#include <stdio.h>
#include <string.h>

int main() {
    char s1[100];
    int i, l;

    printf("Enter a string: ");

    // Use fgets() for safer input
    if (fgets(s1, sizeof(s1), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 1;
    }

    // Remove the trailing newline (if present)
    l = strlen(s1);
    if (s1[l - 1] == '\n') {
        s1[l - 1] = '\0';
        l--;
    }

    // Reverse the string in-place
    for (i = 0; i < l / 2; i++) {
        char temp = s1[i];
        s1[i] = s1[l - 1 - i];
        s1[l - 1 - i] = temp;
    }

    printf("The reversed string is: %s\n", s1);

    return 0;
}

