#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

// For Every XOR of all elements from 1 to n , there exists a pattern :
//  1. If n%4 == 0 , then XOR of all elements from 1 to n is n
//  2. If n%4 == 1 , then XOR of all elements from 1 to n is 1
//  3. If n%4 == 2 , then XOR of all elements from 1 to n is n+1
//  4. If n%4 == 3 , then XOR of all elements from 1 to n is 0
class Solution
{
public:
    int findXOR(int l, int r)
    {
        l--;
        int xor1, xor2;
        if (l % 4 == 0)
        {
            xor1 = l;
        }
        else if (l % 4 == 1)
        {
            xor1 = 1;
        }
        else if (l % 4 == 2)
        {
            xor1 = l + 1;
        }
        else
        {
            xor1 = 0;
        }
        int rem = r % 4;
        if (rem == 0)
        {
            xor2 = r;
        }
        else if (rem == 1)
        {
            xor2 = 1;
        }
        else if (rem == 2)
        {
            xor2 = r + 1;
        }
        else
        {
            xor2 = 0;
        }
        return xor1 ^ xor2;
    }
};