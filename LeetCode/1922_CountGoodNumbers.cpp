#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/count-good-numbers/

class Solution
{
public:
#define MOD 1000000007
    long long power(long long n, long long p)
    {
        if (p == 0)
        {
            return 1;
        }
        long long ans = power(n, p / 2);
        ans *= ans;
        ans %= MOD;
        if (p % 2 == 1)
        {
            ans *= n;
            ans %= MOD;
        }
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        long long oddPlaces = n / 2;
        long long evenPlaces = n / 2 + n % 2;
        return (power(5, evenPlaces) * power(4, oddPlaces)) % MOD;
    }
};