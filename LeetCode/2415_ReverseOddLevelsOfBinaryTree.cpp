#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            vector<int> currVals;
            vector<TreeNode*> currNodes;

            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();

                currVals.push_back(curr->val);
                currNodes.push_back(curr);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(level%2){
                for(int i=0;i<n;i++){
                    currNodes[i]->val=currVals[n-i-1];
                }
            }
            level++;
        }
        return root;
    }
};