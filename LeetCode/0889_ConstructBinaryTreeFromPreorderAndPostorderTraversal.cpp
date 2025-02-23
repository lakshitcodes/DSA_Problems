#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
        TreeNode* solve(int preStart,int preEnd,int postStart,vector<int> &preorder,vector<int> &postorder){
            if(preStart>preEnd){
                return nullptr;
            }
            if(preStart==preEnd){
                return new TreeNode(preorder[preStart]);
            }
            // Left child is the next element in preorder
            int leftVal=preorder[preStart+1];
            // Number of children in left
            int n=1;
            while(postorder[postStart+n-1]!=leftVal){
                n++;
            }
            TreeNode* root=new TreeNode(preorder[preStart]);
            root->left=solve(preStart+1,preStart+n,postStart,preorder,postorder);
            root->right=solve(preStart+n+1,preEnd,postStart+n,preorder,postorder);
    
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            return solve(0,preorder.size()-1,0,preorder,postorder);
        }
    };