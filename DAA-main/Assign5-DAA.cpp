//N-Queens using Backtracking algorithm

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    for (int i = 0; i < row; i++) 
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) 
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensBacktracking(vector<vector<int>>& board, int row, int n) {
    if (row == n) return true; 

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; 

            if (solveNQueensBacktracking(board, row + 1, n))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row)
            cout << (cell ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int n = 4; // Change this for different board sizes
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueensBacktracking(board, 0, n))
        printBoard(board);
    else
        cout << "No solution exists" << endl;

    return 0;
}


// Time Complexity 0(N! * N)
// Space Complexity 0(N^2)