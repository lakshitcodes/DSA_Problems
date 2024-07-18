#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sliding-puzzle/

class Solution
{
public:
    int findZero(string &currPath)
    {
        for (int i = 0; i < 6; i++)
        {
            if (currPath[i] == '0')
            {
                return i;
            }
        }
        return -1; // Dummy Value
    }
    int slidingPuzzle(vector<vector<int>> &board)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, vector<int>> swapDict;
        swapDict[0] = {1, 3};
        swapDict[1] = {0, 4, 2};
        swapDict[2] = {1, 5};
        swapDict[3] = {0, 4};
        swapDict[4] = {1, 3, 5};
        swapDict[5] = {2, 4};
        string puzzle = "";
        string required = "123450";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                puzzle += '0' + board[i][j];
            }
        }
        queue<pair<string, int>> q;
        q.push({puzzle, 0});
        unordered_set<string> visited;
        while (!q.empty())
        {
            auto [currState, moves] = q.front();
            q.pop();
            if (currState == required)
            {
                return moves;
            }
            if (visited.find(currState) == visited.end())
            {
                visited.insert(currState);
                int index = findZero(currState);
                for (auto i : swapDict[index])
                {
                    string temp = currState;
                    swap(temp[index], temp[i]);
                    if (visited.find(temp) == visited.end())
                    {
                        q.push({temp, moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};