#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

class Solution
{
public:
    bool isPossible(int a, int b)
    {
        return (a == 2 || b == 2) && (a != b);
    }
};