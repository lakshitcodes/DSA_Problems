#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/flood-fill/description/

class Solution
{
public:
    void solve(vector<vector<int>> &image, int sr, int sc, int color, int prev, vector<vector<bool>> &visited)
    {
        if (visited[sr][sc] == true)
        {
            return;
        }
        else
        {
            visited[sr][sc] = true;
        }
        image[sr][sc] = color;
        if (sr - 1 >= 0)
        {
            if (image[sr - 1][sc] == prev)
            {
                image[sr - 1][sc] = color;
                solve(image, sr - 1, sc, color, prev, visited);
            }
        }
        if (sc - 1 >= 0)
        {
            if (image[sr][sc - 1] == prev)
            {
                image[sr][sc - 1] = color;
                solve(image, sr, sc - 1, color, prev, visited);
            }
        }
        if (sr + 1 < image.size())
        {
            if (image[sr + 1][sc] == prev)
            {
                image[sr + 1][sc] = color;
                solve(image, sr + 1, sc, color, prev, visited);
            }
        }
        if (sc + 1 < image[0].size())
        {
            if (image[sr][sc + 1] == prev)
            {
                image[sr][sc + 1] = color;
                solve(image, sr, sc + 1, color, prev, visited);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int current = image[sr][sc];
        solve(image, sr, sc, color, current, visited);
        return image;
    }
};