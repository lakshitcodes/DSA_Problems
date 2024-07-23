#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        std::vector<std::pair<int, int>> trains;
        for (int i = 0; i < n; ++i)
        {
            trains.push_back({arr[i], dep[i]});
        }

        std::sort(trains.begin(), trains.end());

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int i = 0; i < n; ++i)
        {
            if (!minHeap.empty() && minHeap.top() < trains[i].first)
            {
                minHeap.pop();
            }

            minHeap.push(trains[i].second);
        }

        return minHeap.size();
    }
};