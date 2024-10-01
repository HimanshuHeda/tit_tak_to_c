#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of words for the game
const char *words[] = {
    "environment",
    "sustainability",
    "python",
    "bootstrap",
    "sqlite",
    "ecommerce",
    "recycling",
    "eco",
    "carbon",
    "conservation"
};

#define MAX_TRIES 6  // Maximum number of incorrect attempts

void printWord(const char *word, const int *guessed) {
    // Display the word with underscores for unguessed letters
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int isWordGuessed(const char *word, const int *guessed) {
    // Check if the whole word has been guessed
    for (int i = 0; word[i] != '\0'; i++) {
        if (!guessed[i]) {
            return 0; // Word is not yet fully guessed
        }
    }
    return 1; // All letters have been guessed
}

int main() {
    // Seed for random word selection
    srand(time(0));
    
    // Select a random word from the list
    const char *word = words[rand() % (sizeof(words) / sizeof(words[0]))];
    int wordLength = strlen(word);
    
    int guessed[wordLength]; // Array to track guessed letters (1 = guessed, 0 = not guessed)
    memset(guessed, 0, sizeof(guessed)); // Initialize all letters as not guessed

    int triesLeft = MAX_TRIES;  // Remaining incorrect attempts
    int correctGuesses = 0;     // Count of correct guesses
    char guessedLetters[26];    // Store the guessed letters
    int numGuessedLetters = 0;  // Number of guessed letters

    printf("Welcome to Hangman!\n");
    printf("You have %d incorrect attempts to guess the word.\n", MAX_TRIES);

    while (triesLeft > 0) {
        printf("\nWord: ");
        printWord(word, guessed);

        printf("Incorrect attempts left: %d\n", triesLeft);
        printf("Guessed letters: ");
        for (int i = 0; i < numGuessedLetters; i++) {
            printf("%c ", guessedLetters[i]);
        }
        printf("\n");

        // Ask the player to guess a letter
        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);  // Convert the guess to lowercase

        // Check if the letter has already been guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < numGuessedLetters; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }
        if (alreadyGuessed) {
            printf("You already guessed '%c'. Try a different letter.\n", guess);
            continue;
        }

        guessedLetters[numGuessedLetters++] = guess;  // Add the guessed letter to the list

        // Check if the guessed letter is in the word
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessed[i] = 1;  // Mark the letter as guessed
                found = 1;
                correctGuesses++;
            }
        }

        if (!found) {
            // Incorrect guess, decrease the number of tries
            printf("Incorrect guess!\n");
            triesLeft--;
        } else {
            // Correct guess, check if the whole word is guessed
            printf("Correct guess!\n");
            if (isWordGuessed(word, guessed)) {
                printf("\nCongratulations! You guessed the word: %s\n", word);
                break;
            }
        }
    }

    if (triesLeft == 0) {
        printf("\nYou've run out of attempts! The word was: %s\n", word);
    }

    return 0;
}
