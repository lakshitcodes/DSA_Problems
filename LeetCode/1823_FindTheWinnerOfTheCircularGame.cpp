#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Method 1 : Using Queue
// TC : O(n*k)
// SC : O(n)

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        queue<int> pq;
        for (int i = 1; i <= n; i++)
        {
            pq.push(i);
        }
        while (pq.size() != 1)
        {
            for (int i = 1; i < k; i++)
            {
                pq.push(pq.front());
                pq.pop();
            }
            pq.pop();
        }
        return pq.front();
    }
};


//Method 2 : 
//TC : O(n)
//SC : O(1)

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};