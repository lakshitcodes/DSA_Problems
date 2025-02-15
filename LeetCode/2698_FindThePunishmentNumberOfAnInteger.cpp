#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

class Solution {
    public:
        bool isPossible(string s,int target){
            if(s=="" && target==0){
                return true;
            }
            if(target<0){
                return false;
            }
    
            for(int i=0;i<s.size();i++){
                string left = s.substr(0,i+1);
                string right=s.substr(i+1);
                int leftNum=stoi(left);
    
                bool check = isPossible(right,target-leftNum);
                if(check){
                    return true;
                }
            }
            return false;
        }
        int punishmentNumber(int n) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int sum=0;
            for(int i=1;i<=n;i++){
                int num = i*i;
                if(isPossible(to_string(num),i)){
                    sum+=num;
                }
            }
            return sum;
        }
    };