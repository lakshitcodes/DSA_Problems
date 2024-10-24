#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/flip-equivalent-binary-trees

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(root1==nullptr && root2==nullptr){
            return true;
        }
        if(root1==nullptr || root2==nullptr){
            return false;
        }
        if(root1->val!=root2->val){
            return false;
        }
        // Checking for both flip and not flip
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};