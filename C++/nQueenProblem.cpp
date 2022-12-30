#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col)
{
    // same column
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void nQueenHelper(int n, int row)
{
    if (row == n)
    {
        // we have reached some solution
        // Print the board matrix
        // return
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    // Place at all possible position and move to smaller problem
    for (int j = 0; j < n; j++)
    {
        if (isPossible(n, row, j))
        {
            // putting cell 1 if possible
            board[row][j] = 1;
            // after putting 1 , we move to next row
            nQueenHelper(n, row + 1);
            // when no more possible location then,
            // we do backtracking here
            board[row][j] = 0;
        }
    }
    return;
}

void placeNQueens(int n)
{
    memset(board, 0, 11 * 11 * sizeof(int));
    nQueenHelper(n, 0);
}

int main()
{
    int n;
    cin >> n;
    placeNQueens(n);
}