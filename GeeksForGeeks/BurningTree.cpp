#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/burning-tree/1

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    void makeGraph(Node *root, unordered_map<int, vector<int>> &graph)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left)
        {
            graph[root->left->data].push_back(root->data);
            graph[root->data].push_back(root->left->data);
        }
        if (root->right)
        {
            graph[root->right->data].push_back(root->data);
            graph[root->data].push_back(root->right->data);
        }
        makeGraph(root->left, graph);
        makeGraph(root->right, graph);
    }
    int minTime(Node *root, int target)
    {
        unordered_map<int, vector<int>> graph;
        makeGraph(root, graph);
        unordered_set<int> visited;
        queue<int> q;
        q.push(target);
        int ans = 0;
        while (!q.empty())
        {

            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int frontElement = q.front();
                q.pop();
                if (visited.find(frontElement) == visited.end())
                {
                    visited.insert(frontElement);
                    for (auto &i : graph[frontElement])
                    {
                        if (visited.find(i) == visited.end())
                        {
                            q.push(i);
                        }
                    }
                }
            }
            ans++;
        }
        return ans - 1;
    }
};