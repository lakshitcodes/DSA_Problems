#include <iostream>

using namespace std;

class SegmentTree{
    // Implementing Max Segment Tree
    private:
    vector<int> tree;
    int n;

    void buildTree(int ind,int low,int high,vector<int> &arr){
        if(low==high){
            tree[ind]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        buildTree(2*ind+1,low,mid,arr);
        buildTree(2*ind+2,mid+1,high,arr);
        tree[ind]=max(tree[2*ind+1],tree[2*ind+2]);
    }
    int query(int ind,int low,int high,int l,int r){
        if(low>r || high<l){
            return INT_MIN;
        }
        if(low>=l && high<=r){
            return tree[ind];
        }
        int mid=low+(high-low)/2;
        int left=query(2*ind+1,low,high,l,mid);
        int right=query(2*ind+2,low,high,mid+1,r);
        return max(left,right);
    }
    void update(int index,int low,int high,int arrIndex,int value){
        if(low==high){
            tree[index]=value;
            return ;
        }
        int mid=low+(high-low)/2;
        if(arrIndex<=mid){
            update(2*index+1,low,mid,arrIndex,value);
        }
        else{
            update(2*index+2,mid+1,high,arrIndex,value);
        }
        tree[index]=max(tree[2*index+1],tree[2*index+2]);
    }
    public:
    SegmentTree(vector<int> &arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(0,0,n-1,arr);
    }
    int query(int l,int r){
        return query(0,0,n-1,l,r);
    }
    void update(int arrIndex,int value){
        update(0,0,n-1,arrIndex,value);
    }
};

int main() {
    
    return 0;
}