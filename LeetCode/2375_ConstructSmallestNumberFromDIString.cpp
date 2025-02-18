#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
    public:
        bool solve(string &curr,int index,string pattern,unordered_set<int> &used){
            if(index==pattern.length()){
                if(pattern[index-1]=='I'){
                    for(int i=curr.back()-'0'+1;i<=9;i++){
                        if(used.find(i)==used.end()){
                            curr+=to_string(i);
                            return true;
                        }
                    }
                }
                else{
                    for(int i=curr.back()-'0'-1;i>=1;i--){
                        if(used.find(i)==used.end()){
                            curr+=to_string(i);
                            return true;
                        }
                    }
                }
                return false;
            }
            if(index==0){
                for(int i=1;i<=9;i++){
                    curr+=to_string(i);
                    used.insert(i);
                    if(solve(curr,index+1,pattern,used)){
                        return true;
                    }
                    used.erase(i);
                    curr.pop_back();
                }
            }else{
                if(pattern[index-1]=='I'){
                    for(int i=curr.back()-'0'+1;i<=9;i++){
                        if(used.find(i)==used.end()){
                            curr+=to_string(i);
                            used.insert(i);
                            if(solve(curr,index+1,pattern,used)){
                                return true;
                            }
                            used.erase(i);
                            curr.pop_back();
                        }
                    }
                }
                else{
                    for(int i=curr.back()-'0'-1;i>=1;i--){
                        if(used.find(i)==used.end()){
                            curr+=to_string(i);
                            used.insert(i);
                            if(solve(curr,index+1,pattern,used)){
                                return true;
                            }
                            used.erase(i);
                            curr.pop_back();
                        }
                    }
                }
            }
            return false;
        }
        string smallestNumber(string pattern) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            unordered_set<int> used;
            string ans="";
            solve(ans,0,pattern,used);
            return ans;
        }
    };