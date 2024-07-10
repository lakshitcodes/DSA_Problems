#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    int N;
    MyStack()
    {
        N = 0;
    }

    void push(int x)
    {
        N++;
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow !" << endl;
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int front = q1.front();
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return front;
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(q1.front());
        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
        return val;
    }

    bool empty()
    {
        return !N;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */