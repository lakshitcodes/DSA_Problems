#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// Time Complexity : O(n^2)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=boxes.length();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ans[i]+=(boxes[j]-'0')*(i-j);
            }
            for(int j=i+1;j<n;j++){
                ans[i]+=(boxes[j]-'0')*(j-i);
            }
        }
        return ans;
    }
};


// Time Complexity : O(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=boxes.length();
        vector<int> ans(n,0);
        int right=boxes[0]=='1';
        for(int j=1;j<n;j++){
            ans[0]+=(boxes[j]-'0')*(j);
            if(boxes[j]=='1'){
                right++;
            }
        }
        int left=0;
        int fromLeft=0;
        int fromRight=ans[0];
        if(boxes[0]=='1'){
            left++;
            right--;
        }
        for(int i=1;i<n;i++){
            ans[i]=fromLeft+left+fromRight-right;
            fromRight-=right;
            fromLeft+=left;
            if(boxes[i]=='1'){
                left++;
                right--;
            }
            
        }
        return ans;
    }
};