#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sum-of-largest-prime-substrings/

class Solution
{
public:
    bool isPrime(long long n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        set<long long> st;
        for (int i = 0; i < s.length(); i++)
        {
            long long curr = 0;
            for (int j = i; j < s.length(); j++)
            {
                curr = curr * 10 + (s[j] - '0');
                if (isPrime(curr))
                {
                    st.insert(curr);
                }
            }
        }
        vector<long long> primes(st.begin(), st.end());
        sort(primes.rbegin(), primes.rend());
        for (int i = 0; i < min(3, (int)primes.size()); i++)
        {
            ans += primes[i];
        }
        return ans;
    }
};