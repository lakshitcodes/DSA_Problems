#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
    private:
        vector<int> values;
    public:
        void setValues(TreeNode* root,int x){
            if(root==NULL){
                return;
            }
            root->val=x;
            values.push_back(x);
            if(root->left){
                setValues(root->left,2*x +1 );
            }
            if(root->right){
                setValues(root->right,2*x + 2);
            }
        }
        FindElements(TreeNode* root) {
            setValues(root,0);
        }
        
        bool find(int target) {
            for(int i=0;i<values.size();i++){
                if(values[i]==target){
                    return true;
                }
            }
            return false;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */