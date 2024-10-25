**Tic Tac Toe Game in C**
This project is a command-line Tic Tac Toe game built in C programming language. This classic game allows two players to play against each other on a 3x3 grid.

**Features**
Two-Player Mode: Player 1 (X) and Player 2 (O) alternate turns.
Winning Detection: Automatically detects when a player has won by matching three symbols in a row, column, or diagonal.
Draw Condition: Declares a draw if the grid is full with no winner.

**How to Play**
Player 1 is assigned the symbol X and Player 2 is assigned the symbol O.
Players take turns choosing a position from 1 to 9 to place their symbol in the grid.
The game ends when one player wins by filling a row, column, or diagonal with their symbol, or if all spaces are filled resulting in a draw.
Game Rules

The 3x3 board positions are numbered as follows:
markdown
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
Enter the position number (1-9) to place your symbol on the board.

**How to Run**
**Clone the repository:**
git clone https://github.com/yourusername/tic_tac_toe_c.git
Compile the tic_tac_toe.c file using GCC:
gcc tic_tac_toe.c -o tic_tac_toe

**Run the game:**
./tic_tac_toe

Requirements
C Compiler (GCC recommended)
Basic knowledge of running C programs on the command line
Example Gameplay
markdown
Player 1 (X), enter position: 5
   |   |   
-----------
 X |   |   
-----------
   |   |   

Player 2 (O), enter position: 1
 O |   |   
-----------
 X |   |   
-----------
   |   |   
   
License
This project is open-source and free to use.
