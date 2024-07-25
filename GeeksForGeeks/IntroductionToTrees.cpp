#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/introduction-to-trees/1

class Solution
{
public:
    int countNodes(int i)
    {
        if (i < 1)
        {
            return 0;
        }
        return 1 << (i - 1);
    }
};