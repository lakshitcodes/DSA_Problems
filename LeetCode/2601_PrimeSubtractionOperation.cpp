#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/prime-subtraction-operation/

class Solution {
public:
    void sieve(vector<bool> &prime){
        prime[0] = prime[1] = false;
        
        for(int i=2;i*i<1005;i++){
            if(prime[i]){
                for(int j=i*i;j<1005;j+=i){
                    prime[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<bool> isPrime(1005,true);
        sieve(isPrime);
        for(int i=nums[0]-1;i>1;i--){
            if(isPrime[i]){
                nums[0]-=i;
                break;
            }
        }
        cout<<nums[0]<<" ";
        for(int i=1;i<nums.size();i++){
            for(int j=nums[i]-1;j>1;j--){
                if(isPrime[j]){
                    if(nums[i-1]<nums[i]-j){
                        nums[i]-=j;
                        break;
                    }
                }
            }
            cout<<nums[i]<<" ";
            if(nums[i-1]>=nums[i]){
                return false;
            }
        }
        return true;

    }
};