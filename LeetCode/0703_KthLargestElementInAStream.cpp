#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int n, vector<int> &nums)
    {
        k = n;
        for (auto &i : nums)
        {
            pq.push(i);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */