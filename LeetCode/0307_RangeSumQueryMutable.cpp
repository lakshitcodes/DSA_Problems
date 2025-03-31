#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/range-sum-query-mutable/


class NumArray {
    vector<int> tree;
    int n;

    void buildTree(int index,int low,int high,vector<int> &nums){
        if(low==high){
            tree[index]=nums[low];
            return;
        }
        int mid=low+(high-low)/2;
        buildTree(2*index+1,low,mid,nums);
        buildTree(2*index+2,mid+1,high,nums);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    void update(int index,int low,int high,int arrIndex,int val){
        if(low==high){
            tree[index]=val;
            return;
        }

        int mid=low+(high-low)/2;
        if(arrIndex<=mid){
            update(2*index+1,low,mid,arrIndex,val);
        }
        else{
            update(2*index+2,mid+1,high,arrIndex,val);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int query(int index,int low,int high,int l,int r){
        if(low>=l && high<=r){
            return tree[index];
        }
        if(l>high || r<low){
            return 0;
        }
        int mid=low+(high-low)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return left+right;
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);
        buildTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */