#include <stdio.h>

#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check if there's a queen in the same row
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return 0;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

int solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1) == 1)
                return 1;
            board[i][col] = 0;
        }
    }

    return 0;
}

int solveNQ() {
    int board[N][N] = {{0}};

    if (solveNQUtil(board, 0) == 0) {
        printf("Solution does not exist");
        return 0;
    }

    printSolution(board);
    return 1;
}

int main() {
    solveNQ();
    return 0;
}
