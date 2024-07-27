#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec
{
private:
    // Helper function to perform preorder serialization.
    void solve(TreeNode *root, string &ans)
    {
        if (root == nullptr)
        {
            ans += "n,"; // Use 'n' to denote null, separated by comma
            return;
        }
        ans += to_string(root->val) + ','; // Add value and separator
        solve(root->left, ans);
        solve(root->right, ans);
    }

    // Helper function to perform deserialization.
    TreeNode *buildTree(queue<string> &nodes)
    {
        if (nodes.empty())
        {
            return nullptr;
        }

        string curr = nodes.front();
        nodes.pop();

        if (curr == "n")
        {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(curr));
        node->left = buildTree(nodes);
        node->right = buildTree(nodes);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        solve(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        string item;
        queue<string> nodes;

        // Split data using comma as delimiter
        while (getline(ss, item, ','))
        {
            nodes.push(item);
        }

        return buildTree(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
