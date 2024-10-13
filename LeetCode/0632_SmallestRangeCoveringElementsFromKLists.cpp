#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems//smallest-range-covering-elements-from-k-lists/description

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Number of arrays
        int k=nums.size();

        //Initialising the min heap
        // minElement, index of the array, index of the current element in that array
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;

        // Initialising the the initial range that is the max and min of all the first elements in the arrays
        int left=INT_MAX,right=INT_MIN;
        for(int i=0;i<k;i++){
            left=min(left,nums[i][0]);
            right=max(right,nums[i][0]);
        
            // Creating a heap to find the current minimum number of all the pointers we will be initialising and then incrementing them forward until one of them reaches the end of the array
            pq.push({nums[i][0],i,0});         
        }
        vector<int> res={left,right};

        while(true){
            auto currElement=pq.top();
            pq.pop();
            int currVal=currElement[0];
            int currList = currElement[1];
            int idx = currElement[2];

            idx++;
            // If we have reached the end of the currList
            if(idx==nums[currList].size()){
                return res;
            }
            // Finding the new value
            int newVal=nums[currList][idx];

            // Pushing the new values
            pq.push({newVal,currList,idx});

            //Updating the curr range
            right=max(right,newVal);
            left=pq.top()[0];

            //If the new range is shorter than the previous one
            if(right-left<res[1]-res[0]){
                res={left,right};
            }
        }
        return res;
    }
};