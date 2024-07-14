#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/number-of-atoms/description

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        string ans = "";
        map<string, int> mp;
        int count = 0, multiplier = 1;
        stack<int> st;
        for (int i = formula.length() - 1; i >= 0; i--)
        {
            if (formula[i] >= 'a' && formula[i] <= 'z')
            {
                int len = 2;
                i--;
                while (i >= 0 && formula[i] >= 'a' && formula[i] <= 'z')
                {
                    len++;
                    i--;
                }
                string atom = formula.substr(i, len);
                mp[atom] += max(1, count) * multiplier;
                count = 0;
            }
            else if (formula[i] >= 'A' && formula[i] <= 'Z')
            {
                string atom(1, formula[i]);
                mp[atom] += max(1, count) * multiplier;
                count = 0;
            }
            else if (formula[i] >= '0' && formula[i] <= '9')
            {
                count = formula[i] - '0';
                int p = 10;
                while (i - 1 >= 0 && formula[i - 1] >= '0' &&
                       formula[i - 1] <= '9')
                {
                    i--;
                    count += p * (formula[i] - '0');
                    p *= 10;
                }
            }
            else if (formula[i] == ')')
            {
                st.push(multiplier);
                multiplier *= max(count, 1);
                count = 0;
            }
            else
            {
                multiplier = st.top();
                st.pop();
            }
        }
        for (auto &[atom, num] : mp)
        {
            ans += atom;
            if (num > 1)
            {
                ans += to_string(num);
            }
        }
        return ans;
    }
};