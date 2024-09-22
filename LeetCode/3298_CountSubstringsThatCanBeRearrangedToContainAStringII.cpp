#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/

class Solution
{
public:
    long long validSubstringCount(string word1, string word2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        vector<int> count(26, 0);

        for (auto &ch : word2)
        {
            count[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> temp(26, 0);
        while (j < word1.length())
        {
            temp[word1[j] - 'a']++;
            bool valid = true;
            for (int k = 0; k < 26; k++)
            {
                if (temp[k] < count[k])
                {
                    valid = false;
                    break;
                }
            }
            while (valid && i <= j)
            {
                ans += word1.length() - j;
                temp[word1[i] - 'a']--;
                i++;

                valid = true;
                for (int k = 0; k < 26; k++)
                {
                    if (temp[k] < count[k])
                    {
                        valid = false;
                        break;
                    }
                }
            }

            j++;
        }

        return ans;
    }
};
