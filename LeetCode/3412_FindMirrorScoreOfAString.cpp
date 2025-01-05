#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-mirror-score-of-a-string/

class Solution {
public:
    long long calculateScore(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<stack<int>> positions(26); 
        long long ans = 0;

        for (int i = 0; i < s.length(); i++) {
            int mirror = 25 - (s[i] - 'a'); 

            if (!positions[mirror].empty()) {
                int j = positions[mirror].top(); 
                positions[mirror].pop();        
                ans += i - j;                 
            } else {
                positions[s[i] - 'a'].push(i);
            }
        }

        return ans;
    }
};