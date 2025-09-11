#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sort-vowels-in-a-string/

class Solution
{
public:
    const string vowels = "AEIOUaeiou";
    int freq[10] = {0};
    vector<int> pos;
    void isVowel(char c, int idx)
    {
        switch (c)
        {
        case 'A':
            freq[0]++;
            pos.push_back(idx);
            break;
        case 'E':
            freq[1]++;
            pos.push_back(idx);
            break;
        case 'I':
            freq[2]++;
            pos.push_back(idx);
            break;
        case 'O':
            freq[3]++;
            pos.push_back(idx);
            break;
        case 'U':
            freq[4]++;
            pos.push_back(idx);
            break;
        case 'a':
            freq[5]++;
            pos.push_back(idx);
            break;
        case 'e':
            freq[6]++;
            pos.push_back(idx);
            break;
        case 'i':
            freq[7]++;
            pos.push_back(idx);
            break;
        case 'o':
            freq[8]++;
            pos.push_back(idx);
            break;
        case 'u':
            freq[9]++;
            pos.push_back(idx);
            break;
        }
    }

    string sortVowels(string s)
    {
        int n = s.size();
#pragma unroll
        for (int i = 0; i < n; i++)
            isVowel(s[i], i);
        //    print(pos);
        int count = 0, v = freq[0], j = 0;
#pragma unroll
        for (int i : pos)
        {
            while (count >= v)
                v += freq[++j];
            s[i] = vowels[j];
            count++;
        }
        return s;
    }
};