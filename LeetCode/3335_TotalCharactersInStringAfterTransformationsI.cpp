#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/total-characters-in-string-after-transformations-i/

class Solution {
public:
    #define MOD 1000000007
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26, 0);  
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        while (t--) {
            vector<long long> nCount(26, 0);
            if (count[25] > 0) {
                nCount[0] = (nCount[0] + count[25]) % MOD; 
                nCount[1] = (nCount[1] + count[25]) % MOD;
            }
            for (int i = 0; i < 25; i++) {
                if (count[i] > 0) {
                    nCount[i + 1] = (nCount[i + 1] + count[i]) % MOD;
                }
            }
            
            count = nCount;
        }
        
        long long total = 0;
        for (long long curr : count) {
            total = (total + curr) % MOD;
        }
        
        return total;
    }
};