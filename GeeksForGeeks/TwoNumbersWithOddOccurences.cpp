#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        long long int xorValue = 0;
        for (int i = 0; i < N; i++)
        {
            xorValue ^= Arr[i];
        }
        long long int diffBits = (xorValue & (xorValue - 1)) ^ xorValue;
        long long int a = 0, b = 0;
        for (int i = 0; i < N; i++)
        {
            if (diffBits & Arr[i])
            {
                a ^= Arr[i];
            }
            else
            {
                b ^= Arr[i];
            }
        }
        if (a > b)
        {
            return {a, b};
        }
        return {b, a};
    }
};