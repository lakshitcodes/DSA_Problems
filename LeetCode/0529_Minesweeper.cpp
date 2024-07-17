#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minesweeper/submissions/1324303917/

class Solution
{
public:
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    int getCount(int i, int j, vector<vector<char>> &board)
    {
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
            int I = i + dx[k];
            int J = j + dy[k];
            if (I >= 0 && J >= 0 && I < board.size() && J < board[0].size() && board[I][J] == 'M')
            {
                count++;
            }
        }
        return count;
    }
    void solve(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y)
    {
        if (x < 0 || x >= board.size() || y >= board[0].size() || y < 0 || visited[x][y])
        {
            return;
        }
        visited[x][y] = true;
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] == 'E')
        {
            int c = getCount(x, y, board);
            if (c == 0)
            {
                board[x][y] = 'B';
                for (int i = 0; i < 8; i++)
                {
                    solve(board, visited, x + dx[i], y + dy[i]);
                }
            }
            else
            {
                board[x][y] = c + '0';
                return;
            }
        }
    }
    vector<vector<char>> updateBoard(
        vector<vector<char>> &board, vector<int> &click)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        solve(board, visited, click[0], click[1]);
        return board;
    }
};