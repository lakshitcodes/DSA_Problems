#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);   
        q.push(NULL);
        int maxi=INT_MIN;
        while(!q.empty()){
            TreeNode* frontElement=q.front();
            q.pop();

            if(frontElement==NULL){
                ans.push_back(maxi);
                maxi=INT_MIN;
                if(!q.empty()){
                    q.push(NULL);

                }
            }
            else{
                maxi=max(maxi,frontElement->val);
                if(frontElement->left){
                    q.push(frontElement->left);
                }
                if(frontElement->right){
                    q.push(frontElement->right);
                }
            }
            
        }   
        return  ans;
    }
};