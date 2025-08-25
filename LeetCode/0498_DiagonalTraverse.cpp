#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/diagonal-traverse/

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        map<int, vector<int>> matrix;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                matrix[i + j].push_back(mat[i][j]);
            }
        }
        stack<int> st;
        vector<int> ans;
        for (auto i : matrix)
        {
            if (i.first % 2 != 0)
            {
                for (auto j : i.second)
                {
                    ans.push_back(j);
                }
            }
            else
            {
                for (auto j : i.second)
                {
                    st.push(j);
                }
                while (!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};