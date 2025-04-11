#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-symmetric-integers/

class Solution {
    public:
        bool isSymmetric(string num){
            if(num.length()&1){
                return false;
            }
            int sum=0;
            int n=num.length();
            for(int i=0;i<n/2;i++){
                sum+=num[i]-'0';
            }
            for(int i=n/2;i<n;i++){
                sum-=num[i]-'0';
            }
            return sum==0;
        }
        int countSymmetricIntegers(int start,int end) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=0;
            for(int i=start;i<=end;i++){
                if(isSymmetric(to_string(i)))   ans++;
            }
            return ans;
        }
    };