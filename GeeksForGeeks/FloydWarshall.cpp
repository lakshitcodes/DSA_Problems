#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution
{
public:
    void
    shortest_distance(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e8;
                }
            }
        }
        for (int k = 0; k < matrix.size(); k++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix.size(); j++)
                {
                    int oc = matrix[i][j];
                    int nc = matrix[i][k] + matrix[k][j];
                    if (nc < oc)
                    {
                        matrix[i][j] = nc;
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 1e8)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};