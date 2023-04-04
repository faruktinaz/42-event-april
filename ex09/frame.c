#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int next_word(char *sentence, int *start, int *end)
{
    int i = *start;
    while (sentence[i] != '\0' && isspace(sentence[i]))
        i++;
    *start = i;
    if (sentence[i] == '\0')
        return (0);
    while (sentence[i] != '\0' && !isspace(sentence[i]))
        i++;
    *end = i;
    return (1);
}

int get_longest_word(char *sentence) {
    int candidate = 0;
    int start = 0;
    int end = 0;
    while (next_word(sentence, &start, &end)) {
        if (end - start > candidate)
            candidate = end - start;
        start = end;
    }
    return (candidate);
}

void fancy_print_words(char *sentence) {
    int longest = get_longest_word(sentence);
    if (longest == 0)
    {
        puts("No words to frame... :(");
        return ;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < longest + 4; i++)
        printf("*");
    printf("\n");
    while (next_word(sentence, &start, &end)) {
        printf("* %.*s", end - start, sentence + start);
        int padding = longest - (end - start);
        for (int i = 0; i < padding + 1; i++)
            printf(" ");
        printf("*\n");
        start = end;
    }
    for (int i = 0; i < longest + 4; i++)
        printf("*");
    printf("\n");
}

int main(int argc, char **argv) {
    char *sentence = NULL;
    int word_index = 0;
    int size = 0;
    argc--;
    argv++;
    while (argv[word_index] != NULL)
    {
        size += strlen(argv[word_index]);
        word_index++;
	}
    sentence = (char *) malloc(sizeof(char) * (size + word_index + 1));
    if (sentence == NULL)
        return (1);
    bzero(sentence, word_index + 1);
    word_index = 0;
    while (argv[word_index] != NULL) {
        strcat(sentence, argv[word_index]);
        strcat(sentence, " ");
        word_index++;
	}
    fancy_print_words(sentence);
    free(sentence);
}