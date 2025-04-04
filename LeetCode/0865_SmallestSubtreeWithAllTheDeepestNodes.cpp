#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
        TreeNode* ans;
        int maxDepth=-1;
    
        int solve(TreeNode* root,int d){
            if(root->left==nullptr && root->right==nullptr){
                if(d>maxDepth){
                    maxDepth=d;
                    ans=root;
                }
                return d;
            }
            int left=0,right=0;
            if(root->left){
                left=solve(root->left,d+1);
            }
            if(root->right){
                right=solve(root->right,d+1);
            }
    
            if(left==right){
                if(left>=maxDepth){
                    maxDepth=left;
                    ans=root;
                }
            }
            return max(left,right);
        }
    
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            solve(root,0);
            return ans;
        }
    };