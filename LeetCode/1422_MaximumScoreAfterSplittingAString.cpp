#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class Solution {
public:
    int maxScore(string s) {
        int length = s.length();
        int ones = 0;
        int tmpScore = s[0] == '0' ? 1 : 0;
        int score = tmpScore;
        
        for (int i = 1; i < length - 1; i++) {
            if (s[i] == '0') {
                tmpScore += 1;
            } else {
                ones++;
                tmpScore -= 1;
            }

            if (tmpScore > score) {
                score = tmpScore;
            }
        }
        
        ones += (s[length - 1] == '1' ? 1 : 0);

        return ones + score;
    }
};