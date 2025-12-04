#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-collisions-on-a-road/

class Solution
{
public:
    int countCollisions(string directions)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        stack<char> road;
        int coll = 0;
        for (char c : directions)
        {
            if (!road.empty() && road.top() == 'R' && c == 'L')
            {
                coll += 2;
                road.pop();
                road.push('S'); // both become stationary;
            }
            else if (!road.empty() && road.top() == 'R' && c == 'S')
            {
                coll += 1;
                road.pop();
                road.push('S');
            }
            else if (!road.empty() && road.top() == 'S' && c == 'L')
            {
                coll += 1;
            }
            else
            {
                road.push(c);
            }
        }

        // R can move ahead safely
        while (!road.empty() && road.top() == 'R')
        {
            road.pop();
        }

        // other R can bump into S/L ahead
        {
            if (road.top() == 'R')
            {
                coll++;
            }
            road.pop();
        }

        return coll;
    }
};