#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/word-ladder-ii/description/

// My Code (TLE)
class Solution
{
private:
    int minSize = INT_MAX;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> mp;
        for (int i = 0; i < wordList.size(); i++)
        {
            mp[wordList[i]] = i;
        }
        queue<vector<int>> q;
        q.push({-1});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<int>> intAns;
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<int> vec = q.front();
            q.pop();
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    dict.erase(it);
                }
            }
            string word;
            if (vec.back() == -1)
            {
                word = beginWord;
            }
            else
                word = wordList[vec.back()];
            if (word == endWord)
            {
                if (intAns.empty())
                    intAns.push_back(vec);
                else
                {
                    if (vec.size() == intAns[0].size())
                    {
                        intAns.push_back(vec);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (dict.count(word))
                    {
                        vec.push_back(mp[word]);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        for (auto &vec : intAns)
        {
            vector<string> temp;
            temp.push_back(beginWord);
            for (int i = 1; i < vec.size(); i++)
            {
                temp.push_back(wordList[vec[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Solution
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(endWord) == wordSet.end())
            return result;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);

        bool found = false;

        while (!currentLevel.empty() && !found)
        {
            for (const string &word : currentLevel)
            {
                wordSet.erase(word);
            }
            for (const string &word : currentLevel)
            {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i)
                {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        temp[i] = c;
                        if (wordSet.find(temp) != wordSet.end())
                        {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord)
                            {
                                found = true;
                            }
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            swap(currentLevel, nextLevel);
            nextLevel.clear();
        }

        if (found)
        {
            vector<string> path = {endWord};
            backtrack(result, path, parents, endWord, beginWord);
        }

        return result;
    }

private:
    void backtrack(vector<vector<string>> &result, vector<string> &path, unordered_map<string, vector<string>> &parents, const string &word, const string &beginWord)
    {
        if (word == beginWord)
        {
            reverse(path.begin(), path.end());
            result.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (const string &parent : parents[word])
        {
            path.push_back(parent);
            backtrack(result, path, parents, parent, beginWord);
            path.pop_back();
        }
    }
};