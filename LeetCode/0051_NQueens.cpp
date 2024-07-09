#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/n-queens/

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        int r = row;
        int c = col;
        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c--;
        }
        while (row >= 0 && col < board.size())
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    void solve(int n, int curr, vector<string> &board, vector<vector<string>> &ans)
    {
        if (n == curr)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(curr, col, board))
            {
                board[curr][col] = 'Q';
                solve(n, curr + 1, board, ans);
                board[curr][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string line = "";
        for (int i = 0; i < n; i++)
        {
            line += '.';
        }
        vector<string> board(n, line);
        vector<vector<string>> ans;
        solve(n, 0, board, ans);
        return ans;
    }
};