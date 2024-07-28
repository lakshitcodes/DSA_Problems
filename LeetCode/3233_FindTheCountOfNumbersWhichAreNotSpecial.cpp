#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int nonSpecialCount(int l, int r)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long total = r - l + 1;
        int root1 = ceil(sqrt(double(l)));
        int root2 = sqrt(r);
        for (int i = root1; i <= root2; i++)
        {
            if (isPrime(i))
            {
                total--;
            }
        }
        return total;
    }
};