#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/partition-labels/

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> last(26,-1);
            for(int i=0;i<s.length();i++){
                last[s[i]-'a']=i;
            }
            vector<int> ans;
            int maxiVal=-1;
            int curr=0;
            for(int i=0;i<s.length();i++){
                maxiVal=max(maxiVal,last[s[i]-'a']);
                if(maxiVal==i){
                    ans.push_back(i-curr+1);
                    maxiVal=-1;
                    curr=i+1;
                }
    
            }
            return ans;
        }
    };