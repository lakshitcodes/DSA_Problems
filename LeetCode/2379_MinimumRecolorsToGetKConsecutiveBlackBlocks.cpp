#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-colors-to-get-k-consectuive-black-blocks/

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=k;
            int w=0,b=0;
            for(int i=0;i<k;i++){
                w+=blocks[i]=='W';
                b+=blocks[i]=='B';
            }
            ans=min(ans,w);
            for(int i=k;i<blocks.size();i++){
                w-=blocks[i-k]=='W';
                b-=blocks[i-k]=='B';
                w+=blocks[i]=='W';
                b+=blocks[i]=='B';
                ans=min(ans,w);
            }
            return ans;
        }
    };