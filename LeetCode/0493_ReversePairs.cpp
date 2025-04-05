#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/reverse-pairs/

class Solution {
    public:
        void merge(vector<int>&arr ,int low,int mid,int high){
            vector<int> temp;
            int left=low;
            int right=mid+1;
            while(left<=mid && right<=high){
                if(arr[left]<=arr[right]){
                    temp.push_back(arr[left++]);
                }
                else{
                    temp.push_back(arr[right++]);
                }
            }
            while(left<=mid){
                temp.push_back(arr[left++]);
            }
            while(right<=high){
                temp.push_back(arr[right++]);
            }
            for(int i=low;i<=high;i++){
                arr[i]=temp[i-low];
            }
        }
        int pairs(vector<int> &arr,int start,int mid,int end){
            int count=0;
            int right=mid+1;
            for(int i=start;i<=mid;i++){
                while(right<=end && arr[i]>(long long)2*arr[right]) right++;
                count+=right-mid-1;
            }
            return count;
        }
        int mergeSort(vector<int> &nums,int start,int end){
            if(start>=end){
                return 0;
            }
            int cnt=0;
            int mid = start + (end-start)/2;
            cnt+=mergeSort(nums,start,mid);
            cnt+=mergeSort(nums,mid+1,end);
            cnt+=pairs(nums,start,mid,end);
            merge(nums,start,mid,end);
            return cnt;
        }
        int reversePairs(vector<int>& nums) {
            return mergeSort(nums,0,nums.size()-1);
        }
    };