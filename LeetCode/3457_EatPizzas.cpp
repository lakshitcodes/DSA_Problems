#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/eat-pizzas/

class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            
            sort(pizzas.begin(),pizzas.end());
            long long totalWeight = 0;
            int m=pizzas.size()/4;
            int odd=(m+1)/2;
            int even=m-odd;
            int n=pizzas.size();
            for(int i=n-1;i>=n-odd;i--){
                totalWeight+=pizzas[i];
            }
            for(int i=n-odd-2;i>=0 && even;i-=2){
                totalWeight+=pizzas[i];
                even--;
            }
             
            return totalWeight;
        }
    };