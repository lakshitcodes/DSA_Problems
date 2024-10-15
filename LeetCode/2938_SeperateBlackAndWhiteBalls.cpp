#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/separate-black-and-white-balls/

class Solution {
public:
    long long minimumSteps(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count=0;
        long long ans=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=s.length()-1-count-i;
                count++;
            }
        }
        return ans;
    }
};