#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-unique-binary-string/

class Solution {
    public:
        int toNum(string s){
            int ans = 0;
            int multiplier = 1;
            for(int i = s.length() - 1; i >= 0; i--){
                ans += (s[i] == '1') * multiplier;
                multiplier *= 2;  
            }
            return ans;
        }
        
        string toString(int num){
            if(num == 0) return "0";  
            
            string s = "";
            while(num > 0){
                if(num % 2 == 0){
                    s += '0';
                } else {
                    s += '1';
                }
                num /= 2;
            }
            reverse(s.begin(), s.end());
            return s;
        }
        
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            unordered_set<int> integers;
            
            for(auto &i : nums){
                integers.insert(toNum(i));
            }
            
            for(int i = 0; i < (1 << n); i++){  
                if(integers.find(i) == integers.end()){
                    string ans = toString(i);
                    return string(n-ans.length(),'0')+ans;
                }
            }
            
            return "";
        }
    };
    