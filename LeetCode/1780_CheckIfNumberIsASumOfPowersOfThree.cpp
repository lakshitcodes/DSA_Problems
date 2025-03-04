#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            map<int,int> vis;
            while(n>0){
                int power=log(n)/log(3);
                if(n>=243 && n<729){
                    power=5;
                }
                if(vis[power]!=1){
                    n-=pow(3,power);
                    vis[power]++;
                    cout<<power<<' ';
                }
                else{
                    break;
                }
            }
            return n==0;
        }
    };