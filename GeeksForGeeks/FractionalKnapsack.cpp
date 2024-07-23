#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    class comparator
    {
    public:
        bool operator()(const Item &a, const Item &b)
        {
            double item1 = (double)a.value / a.weight;
            double item2 = (double)b.value / b.weight;
            return item1 < item2;
        }
    };
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        priority_queue<Item, vector<Item>, comparator> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        double totalVal = 0;
        while (w && !pq.empty())
        {
            Item frontElement = pq.top();
            pq.pop();
            if (frontElement.weight <= w)
            {
                totalVal += (double)frontElement.value;
                w -= frontElement.weight;
            }
            else
            {
                totalVal += ((double)frontElement.value / frontElement.weight) * w;
                w = 0;
            }
        }
        return totalVal;
    }
};