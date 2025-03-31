#include <iostream>

using namespace std;

// Lazy Segment Tree Implementation
// In lazy segment tree, we use lazy propagation to delay updates to segments of the tree.
// This is used when range updates are required for example in adding a value to all elements in a range.
// The lazy array is used to store the pending updates.

// Sum Segment Tree with Lazy Propagation
class LazySegmentTree{
    private:
    vector<int> tree,lazy;
    int n;

    void buildTree(int ind,int low,int high,vector<int> &arr){
        if(low==high){
            tree[ind]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        buildTree(2*ind+1,low,mid,arr);
        buildTree(2*ind+2,mid+1,high,arr);
        tree[ind]=tree[2*ind+1]+tree[2*ind+2];  // Merge the results
    }
    void propagate(int ind,int start,int end){
        if(lazy[ind]!=0){
            tree[ind]+=(end-start+1)*lazy[ind];
            if(start!=end){     // Not a leaf node
                lazy[2*ind+1]+=lazy[ind];  // Propagate to left child   
                lazy[2*ind+2]+=lazy[ind];  // Propagate to right child
            }
            lazy[ind]=0;  // Clear the lazy value
        }
    }   
    // Range Update
    void update(int ind,int low,int high,int l,int r,int value){
        propagate(ind,low,high);  // Propagate any pending updates
        if(low>r || high<l){
            return;  // No overlap
        }
        if(low>=l && high<=r){
            lazy[ind]+=value;  // Update the lazy value
            propagate(ind,low,high);  // Propagate the update
            return;
        }

        int mid=low+(high-low)/2;
        update(2*ind+1,low,mid,l,r,value);  // Update left child    
        update(2*ind+2,mid+1,high,l,r,value);  // Update right child
        tree[ind]=tree[2*ind+1]+tree[2*ind+2];  // Merge the results
    }

    //Range Query
    int query(int ind,int low,int high,int l,int r){
        propagate(ind,low,high);  // Propagate any pending updates
        if(low>r|| high<l){
            return 0;  // No overlap
        }
        if(low>=l && high<=r){
            return tree[ind];  // Total overlap
        }

        int mid=low+(high-low)/2;
        int left=query(2*ind+1,low,mid,l,r);  // Query left child
        int right=query(2*ind+2,mid+1,high,l,r);  // Query right child
        return left+right;  // Merge the results
    }

    public:
    LazySegmentTree(vector<int> &arr){
        n=arr.size();
        tree.resize(4*n);
        lazy.resize(4*n,0);  // Initialize lazy array with 0
        buildTree(0,0,n-1,arr);
    }
    void update(int l,int r,int value){
        update(0,0,n-1,l,r,value);
    }
    int query(int l,int r){
        return query(0,0,n-1,l,r);
    }
};
int main() {
    return 0;
}