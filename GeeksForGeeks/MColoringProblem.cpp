#include<bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, vector<int> &colors, int col, int n, bool graph[101][101])
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && graph[node][k] == 1 && colors[k] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<int> &colors, int m, int n, bool graph[101][101])
    {
        if (node == n)
        {
            return true;
        }
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, colors, i, n, graph))
            {
                colors[node] = i;
                if (solve(node + 1, colors, m, n, graph))
                {
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> colors(n, 0);
        return solve(0, colors, m, n, graph);
    }
};