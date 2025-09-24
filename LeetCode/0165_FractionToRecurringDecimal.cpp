#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/fraction-tu-recurring-decimal/

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (!numerator)
        {
            return "0";
        }

        string ans = "";
        if (numerator > 0 ^ denominator > 0)
        {
            ans += '-';
        }
        long num = labs(numerator);
        long den = labs(denominator);

        long q = num / den;
        long r = num % den;

        ans += to_string(q);
        if (r == 0)
        {
            return ans;
        }
        ans += '.';

        unordered_map<long, int> mp;
        while (r != 0)
        {
            if (mp.find(r) != mp.end())
            {
                int pos = mp[r];

                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else
            {
                mp[r] = ans.length();
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }
        return ans;
    }
};