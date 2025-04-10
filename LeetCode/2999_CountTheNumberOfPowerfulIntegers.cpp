#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-the-number-of-powerful-integers/

class Solution {
    public: 
        long long solve(long long value,long long limit,string s){
            string num=to_string(value);
            if(num.length()<s.length()){
                return 0;
            }
            if(num.length()==s.length()){
                return num>=s ? 1 :0;
            }
    
            // suffix of num of length s.length
            string sNew=num.substr(num.length()-s.length(),s.length());
    
            long long ans=0;
            int n=num.length()-s.length();
    
            for(int i=0;i<n;i++){
                if(limit<(num[i]-'0')){
                    // if current number is greater than limit, than we all take combinations including 0, so limit +1
                    ans+=(long long)pow(limit+1,n-i);
                    return ans;
                }
                ans+=(long long)(num[i]-'0')*(long long)pow(limit+1,n-1-i);
                // 0 to num[i]-1 we have no problem with rest of digits [0->limit]
                // for num[i] we need to check the rest of the digits to ensure all combinations
            }
    
            if(sNew>=s){
                ans++;
            }
            return ans;
    
    
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            return solve(finish,limit,s)-solve(start-1,limit,s);
        }
    };