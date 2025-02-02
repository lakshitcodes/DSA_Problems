#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/

class Solution {
public:
    int findMax(int n,int s,int e,int w,int k){
        int ans=0;
        int dupl=k;
        int dn=n,ds=s,de=e,dw=w;
        if(n>s){
            int minimum = min(s,k);
            n+=minimum;
            s-=minimum;
            k-=minimum;
        }else{
            int minimum = min(n,k);
            s+=minimum;
            n-=minimum;
            k-=minimum;
        }
        if(w>e){
            int minimum = min(e,k);
            w+=minimum;
            e-=minimum;
            k-=minimum;
        }
        else{
            int minimum = min(w,k);
            e+=minimum;
            w-=minimum;
            k-=minimum;
        }
        ans=max(ans,abs(n-s)+abs(w-e));
        k=dupl,n=dn,e=de,s=ds,w=dw;
        if(w>e){
            int minimum = min(e,k);
            w+=minimum;
            e-=minimum;
            k-=minimum;
        }
        else{
            int minimum = min(w,k);
            e+=minimum;
            w-=minimum;
            k-=minimum;
        }
        if(n>s){
            int minimum = min(s,k);
            n+=minimum;
            s-=minimum;
            k-=minimum;
        }else{
            int minimum = min(n,k);
            s+=minimum;
            n-=minimum;
            k-=minimum;
        }
        ans=max(ans,abs(n-s)+abs(w-e));
        return ans;
    }
    int maxDistance(string dir, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=0,s=0,e=0,w=0;
        int ans=0;
        for(auto &i : dir){
            n+=i=='N';
            s+=i=='S';
            e+=i=='E';
            w+=i=='W';
            ans=max(ans,findMax(n,s,e,w,k));
        }
        
        return ans;
    }
};