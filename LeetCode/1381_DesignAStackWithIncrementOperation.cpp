#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack
{
public:
    vector<int> vec;
    int size;
    int currIndex;
    CustomStack(int maxSize)
    {
        size = maxSize;
        currIndex = -1;
        vec.assign(size, -1);
    }

    void push(int x)
    {
        if (currIndex + 1 == size)
        {
            return;
        }
        currIndex++;
        vec[currIndex] = x;
    }

    int pop()
    {
        if (currIndex == -1)
        {
            return -1;
        }
        currIndex--;
        return vec[currIndex + 1];
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < min(k, currIndex + 1); i++)
        {
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */