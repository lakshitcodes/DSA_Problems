#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/merge-sorted-array/description/

// Using Extra Space
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i=0,j=0;
            vector<int> ans;
            while(i<m && j<n){
                if(nums1[i]<nums2[j]){
                    ans.push_back(nums1[i]);
                    i++;
                }
                else{
                    ans.push_back(nums2[j++]);
                }
            }
            while(i<m){
                ans.push_back(nums1[i++]);
            }
            while(j<n){
                ans.push_back(nums2[j++]);
            }
            nums1=ans;
            
        }
    };


// Inplace
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int mIdx=m-1;
            int nIdx=n-1;
            int end=m+n-1;
            while(nIdx>=0){
                if(mIdx>=0 && nums1[mIdx]>nums2[nIdx]){
                    nums1[end]=nums1[mIdx];
                    mIdx--;
                }else{
                    nums1[end]=nums2[nIdx];
                    nIdx--;
                }
                end--;
            }
        }
    };