#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/sort-a-stack/1

// The structure of the class is
class SortedStack
{
public:
    stack<int> s;
    void sort();
};

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack::sort()
{
    if (s.empty())
    {
        return;
    }

    int greatestElement = s.top();
    s.pop();
    stack<int> temp;

    while (!s.empty())
    {
        if (s.top() > greatestElement)
        {
            temp.push(greatestElement);
            greatestElement = s.top();
        }
        else
        {
            temp.push(s.top());
        }
        s.pop();
    }

    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }

    sort();

    s.push(greatestElement);
}