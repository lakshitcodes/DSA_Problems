#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};