#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution
{
public:
    void solve(Node *root, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (!root)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            curr.push_back(root->data);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(root->data);
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
        curr.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(root, curr, ans);
        return ans;
    }
};