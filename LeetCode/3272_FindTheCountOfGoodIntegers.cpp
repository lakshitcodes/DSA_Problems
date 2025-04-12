#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-count-of-good-integers/

class Solution {
    #define ll long long
    ll vecToNum(vector<int> &num){
        ll ans=0;
        for(auto &i : num){
            ans=ans*10+i;
        }
        return ans;
    }
    ll fact(int n){
        ll ans=1;
        for(int i=2;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
    ll TotalPermutations(map<int,int> &m,int n){
        ll totalPerms=fact(n);
        for(auto &i : m){
            totalPerms/=fact(i.second);
        }
        return totalPerms;
    }
    ll PermsWithZero(map<int,int> m,int n){
        if(m.find(0)==m.end() || m[0]==0){
            return 0;
        }
        m[0]--;
        ll permsZero=fact(n-1);
        for(auto &i : m){
            permsZero/=fact(i.second);
        }
        return permsZero;
    }
    ll calc(map<int,int> &m,int n){
        ll a=TotalPermutations(m,n),b=PermsWithZero(m,n);
        return a-b;
    }
public:
    ll ans=0;
    set<map<int,int>> vis;
    void generatePalindrome(vector<int> &num,int left,int right,int k,int n){
        if(left>right){
            ll palin=vecToNum(num);

            if(palin%k==0){
                map<int,int> m;
                while(palin){
                    m[palin%10]++;
                    palin/=10;
                }
                
                if(vis.find(m)==vis.end()){
                    ans+=calc(m,n);
                    vis.insert(m);
                }
            }

            return;
        }

        // Set current digit to all possible values from 0 to 9
        for(int digit=(left==0) ? 1 : 0;digit<=9;digit++){
            num[left]=num[right]=digit;
            generatePalindrome(num,left+1,right-1,k,n);
        }
    }
    long long countGoodIntegers(int n, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> num(n);
        generatePalindrome(num,0,n-1,k,n);
        return ans;
    }
};