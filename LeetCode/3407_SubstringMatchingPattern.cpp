#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/substring-matching-pattern

class Solution {
public:
    bool hasMatch(string s, string p) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int starPos = p.find('*');
    
    string prefix = p.substr(0, starPos);
    string suffix = p.substr(starPos + 1);

    for (int i = 0; i + prefix.length() <= s.length(); i++) {
        if (s.substr(i, prefix.length()) == prefix) {
            for (int j = i + prefix.length(); j <= s.length(); j++) {
                if (s.substr(j, suffix.length()) == suffix) {
                    return true;
                }
            }
        }
    }
    
    return false;
    }
};