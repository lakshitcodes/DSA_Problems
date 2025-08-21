#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-submatrices-with-all-ones/

class Solution
{
public:
    int solve(vector<vector<int>> &mat, int a, int b)
    {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        int bound = n;
        for (int i = a; i < m; i++)
        {
            for (int j = b; j < bound; j++)
            {
                if (mat[i][j])
                {
                    ans++;
                }
                else
                {
                    bound = j;
                }
            }
        }
        return ans;
    }
    int numSubmat(vector<vector<int>> &mat)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += solve(mat, i, j);
            }
        }
        return ans;
    }
};