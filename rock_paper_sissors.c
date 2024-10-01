#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;
    srand(time(NULL)); // seed for random number generation
    computer = rand() % 3; // generate a random number between 0 and 2

    printf("Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ");
    scanf("%d", &user);

    if (user == computer) {
        printf("It's a tie!\n");
    } else if ((user == 0 && computer == 2) || (user == 1 && computer == 0) || (user == 2 && computer == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    printf("Computer chose: ");
    if (computer == 0) {
        printf("Rock\n");
    } else if (computer == 1) {
        printf("Paper\n");
    } else {
        printf("Scissors\n");
    }

    return 0;
}