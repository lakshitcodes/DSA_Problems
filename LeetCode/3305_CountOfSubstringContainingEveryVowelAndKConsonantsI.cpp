#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/

class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int countOfSubstrings(string word, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = word.size();
        int count = 0;

        for (int start = 0; start < n; ++start)
        {
            int consonant = 0;
            unordered_set<char> vowels;
            for (int end = start; end < n; ++end)
            {
                if (isVowel(word[end]))
                {
                    vowels.insert(word[end]);
                }
                else
                {
                    consonant++;
                }

                if (vowels.size() == 5 && consonant == k)
                {
                    ++count;
                    cout << start << " " << end << endl;
                }
                else if (consonant > k)
                {
                    break;
                }
            }
        }
        return count;
    }
};