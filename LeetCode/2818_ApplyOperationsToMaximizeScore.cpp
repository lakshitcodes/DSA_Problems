#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/apply-operations-to-maximize-score/

class Solution {
    public:
        #define ll long long
        vector<bool> sieve;
        void fillSieve(vector<bool> &sieve){
            sieve[0]=sieve[1]=false;
            for(int i=2;i*i<=1e5;i++){
                if(sieve[i]){
                    for(int j=i*i;j<=1e5;j+=i){
                        sieve[j]=false;
                    }
                }
            }
        }
        ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
        int findScore(int n){
            int ans=0;
            for(int i=1;i*i<=n;i++){
                if(n%i==0){
                    if(sieve[i]){
                        ans++;
                    }
                    if(n/i!=i && sieve[n/i]){
                        ans++;;
                    }
                }
            }
            return ans;
        }
        int maximumScore(vector<int>& nums, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            // Filling Sieve for efficient calculation of primes
            sieve.resize(1e5+1,true);
            fillSieve(sieve);
            int n=nums.size();
            
            // Finding Prime Scores of all elements
            vector<int> primeScore(n,0);
            for(int i=0;i<n;i++){
                primeScore[i]=findScore(nums[i]);
            }
    
            // Finding left and right greater primeScore indexes
            vector<int> left(n,-1),right(n,n);
            stack<int> st;
            // Left
            for(int i=0;i<n;i++){
                while(!st.empty() && primeScore[st.top()]<primeScore[i]){
                    st.pop();
                }
                if(!st.empty()){
                    left[i]=st.top();
                }
                st.push(i);
            }
            // Clearing Stack
            st=stack<int>();
            // Right
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && primeScore[st.top()]<=primeScore[i]){
                    st.pop();
                }
                if(!st.empty()){
                    right[i]=st.top();
                }
                st.push(i);
            }
    
            // Sorting by PrimeScore
            vector<pair<int,int>> sortPrime;
            for(int i=0;i<n;i++){
                sortPrime.push_back({nums[i],i});
            }
            sort(sortPrime.begin(),sortPrime.end(),greater<>());
    
            ll ans=1;
            int mod=1e9+7;
            for(int i=0;i<n && k>0;i++){
                int score=sortPrime[i].first;
                int idx=sortPrime[i].second;
                ll range=(ll)(idx-left[idx])*(ll)(right[idx]-idx);
                ans=((ans%mod)*(expo(nums[idx],min((ll)k,range),mod)%mod))%mod;
                k-=range;
            }
            return ans;
        }
    };