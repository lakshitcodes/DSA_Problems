#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-swap/

// Self Implemented
// Time Complexity : O(n^2)
class Solution {
public:
    int maximumSwap(int num) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string s = to_string(num);
        for(int i=0;i<s.length();i++){
            bool found=false;
            int ind=i;
            int diff=0;
            for(int j=s.length()-1;j>i;j--){
                if(s[j]>s[i]){
                    found=true;
                    if(s[j]-s[i]>diff){
                        diff=s[j]-s[i];
                        ind=j;
                    }
                }
            }
            if(found){
                swap(s[i],s[ind]);
                break;
            }
        }
        return stoi(s);
    }
};


// Optimised Approach
// Time Complexity : O(n)

class Solution {
public:
    int maximumSwap(int num) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string s = to_string(num);
        vector<int> lastInd(10,-1);

        // Store the occurences
        for(int i=0;i<s.length();i++){
            lastInd[s[i]-'0']=i;
        }

        //Traverse for each digit
        for(int i=0;i<s.length();i++){
            // Check if there is larger number to the right of the current number
            for(int d=9;d>s[i]-'0';d--){
                if(lastInd[d]>i){
                    // Swap and return
                    swap(s[i],s[lastInd[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};