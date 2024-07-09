#include <bits/stdc++.h>
using namespace std;

// Question Link :https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

class Solution
{
public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        n = n >> k;
        return n & 1;
    }
};