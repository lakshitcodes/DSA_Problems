#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/construct-quad-tree/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/
bool checkValue(vector<vector<int>> &grid, int x, int y, int n)
{
    int val = grid[x][y];
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (grid[i][j] != val)
            {
                return false;
            }
        }
    }
    return true;
}
Node *solve(vector<vector<int>> &grid, int x, int y, int n)
{
    Node *ans = new Node();
    if (checkValue(grid, x, y, n))
    {
        ans->isLeaf = true;
        ans->val = grid[x][y];
    }
    else
    {
        ans->isLeaf = false;
        ans->val = 0;
        ans->topLeft = solve(grid, x, y, n / 2);
        ans->topRight = solve(grid, x, y + n / 2, n / 2);
        ans->bottomLeft = solve(grid, x + n / 2, y, n / 2);
        ans->bottomRight = solve(grid, x + n / 2, y + n / 2, n / 2);
    }
    return ans;
}
class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        Node *ans = solve(grid, 0, 0, grid.size());
        return ans;
    }
};