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

    while (hasBeenWon(board) == false) {
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
    }
    
    endwin();

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

bool hasBeenWon(int arr[3][3]) {
    // All horizontal checks
    for (int i = 0; i < 3; i++) {
        int sum = 0;

        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }

        if (sum == 6 || sum == 3) {
            return true;
        }
    }

    // All vertical checks


    return false;
}