#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
    public:
      int maxLen(vector<int>& arr) {
          unordered_map<int,int> indexes;
          int currSum=0;
          int ans=0;
          indexes[0]=-1;
          for(int i=0;i<arr.size();i++){
              currSum+=arr[i];
              if(indexes.count(currSum)){
                  ans=max(ans,i-indexes[currSum]);
              }else{
                  indexes[currSum]=i;
              }
          }
          return ans;
          
      }
  };