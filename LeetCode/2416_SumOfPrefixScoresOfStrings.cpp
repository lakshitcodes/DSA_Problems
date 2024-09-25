#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

class Solution
{
public:
    class TrieNode
    {
    public:
        int count;
        TrieNode **children;
        TrieNode()
        {
            count = 0;
            children = new TrieNode *[26];
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
        bool containsKey(char ch)
        {
            return children[ch - 'a'] != nullptr;
        }
        TrieNode *get(char ch)
        {
            return children[ch - 'a'];
        }
        void put(char ch, TrieNode *node)
        {
            children[ch - 'a'] = node;
        }
    };
    class Trie
    {
        TrieNode *root;

    public:
        Trie()
        {
            root = new TrieNode();
        }
        void insertWord(string s)
        {
            TrieNode *temp = root;
            for (int i = 0; i < s.length(); i++)
            {
                if (!temp->containsKey(s[i]))
                {
                    temp->put(s[i], new TrieNode());
                }
                temp = temp->get(s[i]);
                temp->count++;
            }
        }
        int returnCount(string s)
        {
            int ans = 0;
            TrieNode *temp = root;
            for (int i = 0; i < s.length(); i++)
            {
                temp = temp->get(s[i]);
                ans += temp->count;
            }
            return ans;
        }
    };
    vector<int> sumPrefixScores(vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        Trie dict;
        for (auto &i : words)
        {
            dict.insertWord(i);
        }
        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            ans.push_back(dict.returnCount(words[i]));
        }
        return ans;
    }
};