#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int swap=0;
        int open=0,close=0;
        int end=s.length()-1;
        int start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                open++;
            }
            if(s[i]==']'){
                close++;
            }
            if(close>open){
                swap++;
                close--;
                open++;
                while(s[end]!='['){
                    end--;
                }
            }
        }
        return swap;
    }
};

int main(){
    cout<<"Enter the string: ";
    return 0;
}