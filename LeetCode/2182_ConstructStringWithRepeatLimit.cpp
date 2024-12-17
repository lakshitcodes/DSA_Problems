#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-string-with-repeat-limit/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(s.rbegin(),s.rend());
        
        string result;
        int freq=1;
        int pointer=0;
        for(int i=0;i<s.length();i++){
            if(!result.empty() && result.back()==s[i]){
                if(freq<repeatLimit){
                    result+=s[i];
                    freq++;
                }
                else{
                    pointer=max(pointer,i+1);
                    while(pointer<s.length() && s[pointer]==s[i]){
                        pointer++;
                    }

                    if(pointer<s.length()){
                        result+=s[pointer];
                        swap(s[i],s[pointer]);
                        freq=1;
                    }else{
                        break;
                    }
                }
            }else{
                result+=s[i];
                freq=1;
            }
        }
        return result;
    }
};