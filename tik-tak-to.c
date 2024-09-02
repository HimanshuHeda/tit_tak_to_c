#include <stdio.h>

// Function declarations
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int checkDraw(char board[3][3]);

int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1;  // Player 1 starts first
    int choice;
    int row, col;
    int gameStatus = 0;  // 0 = continue, 1 = win, -1 = draw

    while (gameStatus == 0) {
        printBoard(board);
        player = (player % 2) ? 1 : 2;

        // Ask player to make a move
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        // Convert choice to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the chosen cell is already occupied
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = (player == 1) ? 'X' : 'O';
            gameStatus = checkWin(board);
            if (gameStatus == 0) {
                gameStatus = checkDraw(board);
            }
            player++;
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    printBoard(board);

    if (gameStatus == 1) {
        printf("==> Player %d wins!\n", --player);
    } else {
        printf("==> It's a draw!\n");
    }

    return 0;
}

// Function to print the board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check for a win
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

// Function to check for a draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return -1;
}
