#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sudoku-solver/

bool isSafe(int row, int col, vector<vector<char>> &board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] - '0' == val)
        {
            return false;
        }
        if (board[i][col] - '0' == val)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] - '0' == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == '.')
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val + '0';
                        bool possSol = solve(board);
                        if (possSol)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};