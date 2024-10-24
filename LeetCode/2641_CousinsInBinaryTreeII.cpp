#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/cousins-in-binary-tree-ii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int other,int idx,vector<int> &levels){
        if(root==nullptr){
            return;
        }
        root->val = levels[idx]-other-root->val;
        int right=0,left=0;
        if(root->left){
            left=root->left->val;
        }
        if(root->right){
            right=root->right->val;
        }
        solve(root->left,right,idx+1,levels);
        solve(root->right,left,idx+1,levels);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                sum+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            levels.push_back(sum);
        }
        solve(root,0,0,levels);
        return root;
    }
};