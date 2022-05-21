#include <ncurses.h>
#include <stdio.h>
#include <stdbool.h>
#include "tictac.h"

int main() {
    initscr();

    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };


    char currPlayer = 'O';

    int row, col = 0;
    bool gameFinished = false;

    while (gameFinished == false) {
        clear();
        printBoard(board);

        printw("It is Player %c's turn\n", currPlayer); 

        printw("Input row and col\n");
        scanw("%d %d", &row, &col);

        if (currPlayer == 'O')
            board[row][col] = 2;
        else  
            board[row][col] = 1;



        if (currPlayer == 'O')
            currPlayer = 'X';
        else
            currPlayer = 'O';

        refresh();
        int status = hasBeenWon(board);

        if (status != 0) {
            gameFinished = true;
        }
 
    }
    
    endwin();

    getStatus(board);

}

void printBoard(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = arr[i][j];

            if (val == 0)
                printw("_ ");
            if (val == 1)
                printw("X ");
            if (val == 2)
                printw("O ");
        }

        printw("\n");
    }
}

int hasBeenWon(int arr[3][3]) {
    // All horizontal checks
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
            return arr[i][0];
        }
    }


    // All vertical checks

    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == arr[1][i] && arr[0][i]== arr[2][i]) {
            return arr[0][i];

        }
    }

    // Diagonals check
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
        return arr[0][0];
    }

    if (arr[0][2] == arr[1][1] && arr[0][0] == arr[2][0]) {
         return arr[0][2];
    }

    return 0;
}

void getStatus(int arr[3][3]) {
      int status = hasBeenWon(arr);
        if (status != 0) {
            char player;
            if (status == 1) {
                player = 'X';
            } else {
                player = 'O';
            }
            printf("Player %c has won! 🎉\n", player);
        }
}