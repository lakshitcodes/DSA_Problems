#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int x = log2(n);
        int setBits = x * (1 << (x - 1));
        int greaterBits = n - (1 << x) + 1;
        int rest = n - (1 << x);
        return setBits + greaterBits + countSetBits(rest);
    }
};