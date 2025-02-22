#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
        TreeNode* solve(int index,vector<pair<int,int>> &values){
            if(index==values.size()){
                return nullptr;
            }
            // Create the curr node
            TreeNode* ans=new TreeNode(values[index].first);
            int level=values[index].second;
            // index++;
            
            // If next node is the next level then place it on the left
            if(index+1<values.size() && values[index+1].second==level+1){
                ans->left=solve(index+1,values);
            }
    
            // If the next level is less than equal to currLevel, then its either its sibling or part of upper tree
            if(index+1<values.size() && values[index+1].second<=level){
                return ans;
            }
            index+=2;
            while(index<values.size()){
                if(values[index].second<=level){
                    return ans;
                }
                if(values[index].second==level+1){
                    ans->right=solve(index,values);
                    return ans;
                }
                index++;
            }
            return ans;
        }
        TreeNode* recoverFromPreorder(string traversal) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            vector<pair<int,int>> values;
            for(int i=0;i<traversal.size();i++){
                int currLevel=0;
                while(i<traversal.size() && traversal[i]=='-'){
                    i++;
                    currLevel++;
                }
                int val=0;
                while(i<traversal.size() && traversal[i]!='-'){
                    val=val*10 + (traversal[i++]-'0');
                }
                i--;
                values.push_back({val,currLevel});
                // cout<<val<<" "<<currLevel<<endl;
            }
            int index=0;
            return solve(index,values);
        }
    };