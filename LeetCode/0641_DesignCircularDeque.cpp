#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/design-circular-deque

class MyCircularDeque
{
public:
    vector<int> v;
    int front, end, size, capacity;

    MyCircularDeque(int k)
    {
        v = vector<int>(k, -1);
        front = 0;
        end = 0;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        front = ((front - 1) + capacity) % capacity;

        v[front] = value;

        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        v[end] = value;
        end = (end + 1) % capacity;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        v[front] = -1;

        front = (front + 1) % capacity;

        size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }

        if (end == 0)
        {
            end = capacity - 1;
        }
        else
        {
            end--;
        }
        v[end] = -1;

        size--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return v[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        if (end == 0)
        {
            return v[capacity - 1];
        }
        else
        {
            return v[end - 1];
        }
    }

    bool isEmpty() { return (size == 0); }

    bool isFull() { return (size == capacity); }
};