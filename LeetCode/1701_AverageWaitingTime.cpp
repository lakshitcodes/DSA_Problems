#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/average-waiting-time/description

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        double totalWaitingTime = 0;
        int currTime = 0;
        for (auto &i : customers)
        {
            int arrivalTime = i[0];
            int orderTime = i[1];
            if (currTime < arrivalTime)
            {
                currTime = arrivalTime;
            }
            totalWaitingTime += currTime - arrivalTime + orderTime;
            currTime += orderTime;
        }
        int n = customers.size();
        return totalWaitingTime / n;
    }
};