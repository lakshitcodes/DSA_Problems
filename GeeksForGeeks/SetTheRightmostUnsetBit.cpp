#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

class Solution
{
public:
    int setBit(int n)
    {
        return n | (n + 1);
    }
};