#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder
{
    priority_queue<int> low;                             // lower half
    priority_queue<int, vector<int>, greater<int>> high; // upper half

public:
    MedianFinder()
    {
        // Do Nothing
    }

    void addNum(int num)
    {
        if (low.empty() || num <= low.top())
        {
            low.push(num);
        }
        else
        {
            high.push(num);
        }

        // Balance the heaps
        if (low.size() > high.size() + 1)
        {
            high.push(low.top());
            low.pop();
        }
        else if (high.size() > low.size())
        {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian()
    {
        if (low.size() > high.size())
        {
            return low.top(); // Odd number of elements
        }
        else
        {
            return (low.top() + high.top()) / 2.0; // Even number of elements
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
