#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/surrounded-regions/description/

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        board[i][j] = 'S';
        if (i + 1 < board.size() && board[i + 1][j] == 'O')
        {
            dfs(board, i + 1, j);
        }
        if (i - 1 >= 0 && board[i - 1][j] == 'O')
        {
            dfs(board, i - 1, j);
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == 'O')
        {
            dfs(board, i, j + 1);
        }
        if (j - 1 >= 0 && board[i][j - 1] == 'O')
        {
            dfs(board, i, j - 1);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, 0, i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O')
            {
                dfs(board, m - 1, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'S')
                {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};