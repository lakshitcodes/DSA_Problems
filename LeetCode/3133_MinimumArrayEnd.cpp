#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-array-end

class Solution {
public:
    string convertToBinary(int n){
        if(n==0){
            return to_string(0);
        }
        string s="";
        while(n>0){
            s=to_string(n%2)+s;
            n/=2;
        }
        return s;
    }
    long long convertToDecimal(string s){
        long long ans=0;
        long long mask = 1;
        for(int i=63;i>=0;i--){
            if(s[i]=='1'){
                ans+=mask;
            }
            mask<<=1;
        }
        return ans;
    }
    long long minEnd(int n, int x) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // The thought process behind this is that for AND to be equal to x, all the numbers should have set bits which are set in x
        // Now only those bits would be increased in order which are zero
        // Since we have considered our current x as the first because this is the first element with those bits set
        // We will convert n-1 to binary and then set those bits in our x accordingly which were previously zero
        // And simply convert it to decimal later on in the final stage

        string binaryX = convertToBinary(x);
        string binaryN = convertToBinary(n-1);
        int xLen = binaryX.length();
        string mask = string(64-xLen,'0');
        binaryX = mask+binaryX;
        int i=binaryX.length()-1;
        int j=binaryN.length()-1;
        while(i>=0 && j>=0){
            if(binaryX[i]=='0'){
                binaryX[i]=binaryN[j];
                j--;
            }
            i--;
        }
        return convertToDecimal(binaryX);
    }
};