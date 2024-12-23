#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

class Solution {
public:
    int findSwaps(vector<int> &curr) {
        vector<int> sortedCurr = curr;
        sort(sortedCurr.begin(), sortedCurr.end());

        // Create a mapping of value -> index in sorted order
        unordered_map<int, int> pos;
        for (int i = 0; i < sortedCurr.size(); i++) {
            pos[sortedCurr[i]] = i;
        }

        // Track visited indices to avoid infinite loops
        vector<bool> visited(curr.size(), false);
        int swaps = 0;

        for (int i = 0; i < curr.size(); i++) {
            if (visited[i] || pos[curr[i]] == i) {
                // Already visited or in correct position
                continue;
            }

            // Find cycle size
            int cycleSize = 0;
            int x = i;

            while (!visited[x]) {
                visited[x] = true;
                x = pos[curr[x]];
                cycleSize++;
            }

            // For a cycle of size k, we need (k - 1) swaps
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if (!root) return 0; // Handle edge case for empty tree

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> curr;

            // Process current level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);

                // Add children to queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Calculate minimum swaps for the current level
            ans += findSwaps(curr);
        }

        return ans;
    }
};
