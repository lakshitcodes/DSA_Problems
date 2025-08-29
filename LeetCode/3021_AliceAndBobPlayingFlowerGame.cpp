#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/alice-and-bob-playing-flower-game/

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long nOdd = (n + 1) / 2;
        long long nEven = n / 2;
        long long mOdd = (m + 1) / 2;
        long long mEven = m / 2;
        return nOdd * mEven + nEven * mOdd;
    }
};