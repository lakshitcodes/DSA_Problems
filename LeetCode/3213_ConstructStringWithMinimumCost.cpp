#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/construct-string-with-minimum-cost/description/

// Method 1 : Using DP
// TC : O(n^3) (Due to Substr function)
// SC : O(n)
//  This will give TLE
class Solution
{
public:
    int minimumCost(std::string target, std::vector<std::string> &words, std::vector<int> &costs)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = target.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; ++i)
        {
            if (dp[i] == INT_MAX)
                continue;
            for (int j = 0; j < words.size(); ++j)
            {
                string word = words[j];
                int len = word.length();
                if (i + len <= n && target.substr(i, len) == word)
                {
                    dp[i + len] = min(dp[i + len], dp[i] + costs[j]);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

// Method 2 : Using Trie
//  TC : O(n*n)
//  SC : O(n)

class TrieNode
{
public:
    TrieNode *children[26];
    int cost;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        cost = INT_MAX;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word, int cost)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->cost = min(cost, node->cost);
    }
    int search(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (!node->children[index])
            {
                return -1;
            }
            node = node->children[index];
        }
        return node->cost;
    }
};

class Solution
{
public:
    int minimumCost(string target, vector<string> &words, vector<int> &cost)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        Trie trie;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            trie.insert(words[i], cost[i]);
        }
        int targetLength = target.length();
        vector<int> dp(targetLength + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < targetLength; i++)
        {
            if (dp[i] == INT_MAX)
            {
                continue;
            }
            TrieNode *root = trie.root;
            for (int j = i; j < targetLength; j++)
            {
                int idx = target[j] - 'a';
                if (!root->children[idx])
                {
                    break;
                }
                root = root->children[idx];
                if (root->cost != INT_MAX)
                {
                    dp[j + 1] = min(dp[j + 1], dp[i] + root->cost);
                }
            }
        }
        return dp[targetLength] == INT_MAX ? -1 : dp[targetLength];
    }
};