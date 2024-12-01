#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        for(int i=0;i<arr.size();i++){
            for(int j=0;j!=i && j<arr.size();j++){
                if(arr[i]==2*arr[j] || arr[j]==arr[i]*2){
                    return true;
                }
            }
        }
        return false;
    }
};