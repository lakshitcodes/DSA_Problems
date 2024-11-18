#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/defuse-the-bomb/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        int n=code.size();
        for(int i=0;i<n;i++){
            int temp=0;
            if(k>=0){
                for(int j=i+1;j<=i+k;j++){
                    temp+=code[j%n];
                }
            }
            else{
                for(int j=i-1;j>=i+k;j--){
                    temp+=code[(j+n)%n];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};