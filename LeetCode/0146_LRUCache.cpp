#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lru-cache/

// Solution Hereclass LRUCache {
public:
queue<int> q;
vector<int> cache;
LRUCache(int capacity)
{
    cache.resize(capacity, -1);
}

int get(int key)
{
    return cache[key];
}

void put(int key, int value)
{
    if (cache[key] == -1)
    {
        cache[key] = value;
        q.push(key);
    }
    else
    {
        cache[q.front()] = value;
        q.push(q.front());
        q.pop();
    }
}
}
;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */