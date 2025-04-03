#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/queue-construction-by-height/


class Solution {
    public:
        static bool comparator(vector<int> &a,vector<int> &b){
            return a[0]==b[0] ? a[1]<b[1] : a[0]<b[0];
        }
        void print(vector<vector<int>> &arr){
            for(auto &i : arr){
                cout<<i[0]<<" "<<i[1]<<endl;
            }
            cout<<endl<<endl;
        }
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=people.size();
            sort(people.begin(),people.end(),comparator);
    
            // The approach is to sort in ascending order and then leave exactly k possible spaces in front of the current element where greater elements can be placed
            // Here since we have to also consider the equal elements , thus when placing any element, we count the available spaces and those which are equal to the current element, when the count equals the required value, we place the person there and then move to the next person
    
            vector<vector<int>> ans(n,{-1,-1});
    
            for(auto &i : people){
                int val=i[0];
                int pos=i[1];
                int idx=0;
                for(int j=0;j<n;j++){
                    if(idx==pos && ans[j][0]==-1){
                        ans[j]=i;
                        // print(ans);
                        break;
                    }
                    if(ans[j][0]==-1 || ans[j][0]==val){
                        idx++;
                    }
                }
            }
            return ans;
    
        }
    };