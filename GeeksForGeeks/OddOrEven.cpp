#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/odd-or-even3618/1

class Solution
{
public:
    string oddEven(int n)
    {
        if (n & 1)
        {
            return "odd";
        }
        return "even";
    }
};