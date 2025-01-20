#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/first-completely-painted-row-or-column/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int,int> mp;
        int m=mat.size();
        int n=mat[0].size();

        //O(m*n)
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }

        // O(m*n)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=mp[mat[i][j]];
            }
        }

        vector<int> rows(m,INT_MIN);
        vector<int> cols(n,INT_MIN);

        // O(m*n)
        for(int i=0;i<m;i++){
            rows[i]=*max_element(mat[i].begin(),mat[i].end());
        }

        // O(m*n)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cols[i]=max(cols[i],mat[j][i]);
            }
        }

        //O(m+n)
        return min(*min_element(rows.begin(),rows.end()),*min_element(cols.begin(),cols.end()));
    }

    // Total Time Complexity : 4*(m*n) + m+n => O(m*n)
};