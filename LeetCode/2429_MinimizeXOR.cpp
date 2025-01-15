#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimize-xor/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int bitCount = __builtin_popcount(num2);
        int ans=0;

        for(int i=31;i>=0;i--){
            if(num1&(1<<i) && bitCount){
                ans|=(1<<i);
                bitCount--;
            }
        }

        for(int i=0;i<=31 && bitCount;i++){
            if(!(ans&(1<<i))){
                ans|=(1<<i);
                bitCount--;
            }
        }
        return ans;
    }
};