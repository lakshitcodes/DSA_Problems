#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/closest-prime-numbers-in-range/

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<bool> sieve(right+1,false);
            // Filling Sieve
            for(int i=2;i*i<=right;i++){
                if(!sieve[i]){
                    for(int j=i*i;j<=right;j+=i){
                        sieve[j]=true;
                    }
                }
            }
            vector<int> primes;
            for(int i=max(left,2);i<=right;i++){
                if(!sieve[i]){
                    primes.push_back(i);
                }
            }
            if(primes.size()<2){
                return {-1,-1};
            }
            int one=primes[0];
            int two=primes[1];
            int minDiff=two-one;
            for(int i=2;i<primes.size();i++){
                if(primes[i]-primes[i-1]<minDiff){
                    minDiff=primes[i]-primes[i-1];
                    one=primes[i-1];
                    two=primes[i];
                }
            }
            return {one,two};
        }
    };