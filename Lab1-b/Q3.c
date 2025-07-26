#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LEN];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Convert to lowercase
    for (int i = 0; paragraph[i]; i++) {
        paragraph[i] = tolower(paragraph[i]);
    }

    // Tokenize and count
    char *token = strtok(paragraph, " ,.-\n");
    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], token);
            count[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.-\n");
    }

    // Print frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}
