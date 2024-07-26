#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        queue<pair<Node *, pair<int, int>>> pq;
        map<int, vector<int>> mp;
        pq.push({root, {0, 0}});
        while (!pq.empty())
        {
            auto front = pq.front();
            pq.pop();
            Node *element = front.first;
            int hd = front.second.first;
            int lvl = front.second.second;
            mp[hd].push_back(element->data);
            if (element->left)
            {
                pq.push({element->left, {hd - 1, lvl + 1}});
            }
            if (element->right)
            {
                pq.push({element->right, {hd + 1, lvl + 1}});
            }
        }
        vector<int> ans;
        for (auto dis : mp)
        {
            ans.push_back(dis.second.back());
        }
        return ans;
    }
};