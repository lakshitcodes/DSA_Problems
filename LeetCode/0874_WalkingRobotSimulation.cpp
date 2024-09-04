#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems//walking-robot-simulation/

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        set<pair<int, int>> mapObs;
        for (auto &i : obstacles)
        {
            mapObs.insert({i[0], i[1]});
        }
        int x = 0, y = 0;
        int xDir = 0, yDir = 1;
        int ans = 0;
        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] == -2)
            {
                if (xDir != 0)
                {
                    yDir = xDir;
                    xDir = 0;
                }
                else
                {
                    xDir = -yDir;
                    yDir = 0;
                }
            }
            else if (commands[i] == -1)
            {
                if (xDir != 0)
                {
                    yDir = -xDir;
                    xDir = 0;
                }
                else
                {
                    xDir = yDir;
                    yDir = 0;
                }
            }
            else
            {
                for (int d = 1; d <= commands[i]; d++)
                {
                    if (mapObs.find({x + xDir, y + yDir}) != mapObs.end())
                    {
                        break;
                    }
                    x = x + xDir;
                    y = y + yDir;
                    ans = max(ans, x * x + y * y);
                    cout << x << " " << y << endl;
                }
            }
        }
        return ans;
    }
};