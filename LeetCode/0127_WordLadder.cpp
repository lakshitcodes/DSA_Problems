#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/word-ladder/description/

class Solution
{
public:
    vector<string> foundMatching(string word, vector<string> &wordList, unordered_set<string> &visited)
    {
        vector<string> ans;
        for (auto wordTemp : wordList)
        {
            int count = 0;
            for (int idx = 0; idx < word.size(); idx++)
            {
                if (word[idx] != wordTemp[idx])
                {
                    if (count)
                    {
                        count++;
                        break;
                    }
                    count++;
                }
            }
            if (count == 1)
            {
                if (visited.find(wordTemp) == visited.end())
                {
                    ans.push_back(wordTemp);
                }
            }
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        while (!q.empty())
        {
            auto [word, transformation] = q.front();
            q.pop();
            cout << word << " " << transformation << endl;
            if (word == endWord)
            {
                return transformation;
            }
            if (visited.find(word) == visited.end())
            {
                visited.insert(word);
                vector<string> temp = foundMatching(word, wordList, visited);
                for (auto tempWord : temp)
                {
                    q.push({tempWord, transformation + 1});
                }
            }
        }
        return 0;
    }
};