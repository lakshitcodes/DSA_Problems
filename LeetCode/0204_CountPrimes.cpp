#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-primes/description/

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }
        vector<int> sieve(n + 1, 0);
        for (int i = 2; i * i <= n; i++)
        {
            if (sieve[i] == 0)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    sieve[j] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (!sieve[i])
                count++;
        }
        return count;
    }
};