#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/candy/description/

// Using Heap
// Time Complexity : O(nlogn)
class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };
    int candy(vector<int> &ratings)
    {
        // element,index
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        int n = ratings.size();
        int ans = n;
        unordered_map<int, int> countMap;
        for (int i = 0; i < n; i++)
        {
            pq.push({ratings[i], i});
            countMap[i] = 1;
        }
        while (!pq.empty())
        {
            auto &[element, index] = pq.top();
            pq.pop();
            int maxi = countMap[index];
            if (index > 0 && ratings[index - 1] < ratings[index])
            {
                maxi = max(maxi, countMap[index - 1] + 1);
            }
            if (index < n - 1 && ratings[index + 1] < ratings[index])
            {
                maxi = max(maxi, countMap[index + 1] + 1);
            }
            if (maxi > countMap[index])
            {
                ans += maxi - countMap[index];
                countMap[index] = maxi;
            }
        }
        return ans;
    }
};

// Greedy Approach
//  Time Complexity : O(n)

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = ratings.size();
        vector<int> candy(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};