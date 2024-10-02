#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 6

void hangmanGame() {
    char word[MAX_WORD_LENGTH];
    char guessedWord[MAX_WORD_LENGTH];
    int guessesLeft = MAX_GUESSES;
    int i, j;

    // Initialize the word and guessed word arrays
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word[i] = '\0';
        guessedWord[i] = '_';
    }

    // Choose a random word from a predefined list
    printf("The Word List looks like this : ");
    printf("\n 1. apple \n 2. banana \n 3. cherry \n 4. date \n 5. elderberry \n");
    char *wordList[] = {"apple", "banana", "cherry", "date", "elderberry"};
    srand(time(NULL));
    strcpy(word, wordList[rand() % 5]);

    // Game loop
    while (guessesLeft > 0) {
        printf("Guessed word: ");
        for (i = 0; i < strlen(word); i++) {
            printf("%c ", guessedWord[i]);
        }
        printf("\n");

        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);

        int correctGuess = 0;
        for (i = 0; i < strlen(word); i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            guessesLeft--;
            printf("Incorrect guess! %d guesses left.\n", guessesLeft);
        }

        int won = 1;
        for (i = 0; i < strlen(word); i++) {
            if (guessedWord[i] == '_') {
                won = 0;
                break;
            }
        }

        if (won) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    if (guessesLeft == 0) {
        printf("Game over! The word was %s.\n", word);
    }
}

int main() {
    hangmanGame();
    return 0;
}