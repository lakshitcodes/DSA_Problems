#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    void solve(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        for (auto &i : root->children)
        {
            solve(i, ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};