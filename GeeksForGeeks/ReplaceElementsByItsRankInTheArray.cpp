#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        unordered_map<int, int> rank;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto number : arr)
        {
            pq.push(number);
        }
        int count = 1;
        while (!pq.empty())
        {
            if (rank.find(pq.top()) == rank.end())
            {
                rank[pq.top()] = count;
                count++;
            }
            pq.pop();
        }
        for (int i = 0; i < N; i++)
        {
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};