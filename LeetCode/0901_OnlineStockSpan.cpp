#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/online-stock-span/description/

//----------------------Brute Force------------------------------
class StockSpanner
{
public:
    stack<int> st, temp;
    StockSpanner()
    {
        // do literally nothing
    }

    int next(int price)
    {
        int val = 1;
        while (!st.empty() && st.top() <= price)
        {
            temp.push(st.top());
            st.pop();
            val++;
        }
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        st.push(price);
        return val;
    }
};

// --------------------------Optimised Approach---------------------------------
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
        // do literally nothing
    }

    int next(int price)
    {
        int curPrice = price;
        int curSpan = 1;
        while (!st.empty() && st.top().first <= price)
        {
            auto prev = st.top();
            st.pop();
            curSpan += prev.second;
        }
        st.push({curPrice, curSpan});
        return curSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */