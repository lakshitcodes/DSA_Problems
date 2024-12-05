#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string start, string target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=start.size();
        for(int i=0, j=0; i<n || j<n; i++, j++){
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;
            char c=start[i];
            if (c !=target[j]) return false;
            if (c =='L' && i<j) return false;
            if (c =='R' && i>j) return false;
        }
        return true;
    }
};