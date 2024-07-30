#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/graph-and-vertices/1

class Solution
{
public:
    long long count(int n)
    {
        int edges = n * (n - 1) / 2;
        return 1LL << edges;
    }
};