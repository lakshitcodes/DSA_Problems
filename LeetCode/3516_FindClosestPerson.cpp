#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-closest-person/

class Solution {
    public:
        int findClosest(int x, int y, int z) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            if(abs(x-z)==abs(y-z)){
                return 0;
            }
            if(abs(x-z)>abs(y-z)){
                return 2;
            }
            return 1;
                
        }
    };