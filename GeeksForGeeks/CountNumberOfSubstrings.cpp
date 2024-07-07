#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

class Solution
{
public:
    long long substrCountWithAtleastK(string s, int k)
    {
        int n = s.length();
        int i = 0, j = 0;
        vector<int> count(26, 0);
        int f = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            while (j < n && f < k)
            {
                count[s[j] - 'a']++;
                if (count[s[j] - 'a'] == 1)
                {
                    f++;
                }
                j++;
            }
            if (f >= k)
            {
                ans += n - j + 1;
            }
            count[s[i] - 'a']--;
            if (count[s[i] - 'a'] == 0)
            {
                f--;
            }
        }
        return ans;
    }

    long long int substrCount(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        ans = substrCountWithAtleastK(s, k) - substrCountWithAtleastK(s, k + 1);

        return ans;
    }
};