#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/word-search/description/

class Solution
{
public:
    bool solve(vector<vector<char>> &board, int i, int j, string word, int index, vector<vector<bool>> &visited)
    {
        if (index >= word.length())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return false;
        }
        if (visited[i][j])
        {
            return false;
        }
        visited[i][j] = true;
        if (board[i][j] == word[index] && index == word.length() - 1)
        {
            return true;
        }
        if (board[i][j] == word[index])
        {
            bool top = solve(board, i - 1, j, word, index + 1, visited);
            bool right = solve(board, i, j + 1, word, index + 1, visited);
            bool left = solve(board, i, j - 1, word, index + 1, visited);
            bool down = solve(board, i + 1, j, word, index + 1, visited);

            visited[i][j] = false;
            return top || right || left || down;
        }
        else
        {
            visited[i][j] = false;
            return false;
        }
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (solve(board, i, j, word, 0, visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};