#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool flag;
    TrieNode()
    {
        children.resize(26);
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        flag = false;
    }
    bool containsKey(char ch)
    {
        return children[ch - 'a'] != nullptr;
    }
    void put(char ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }
    TrieNode *get(char ch)
    {
        return children[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
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

    // tc -> O(len of word)
    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return false;
            }
        }
        return node->flag;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */