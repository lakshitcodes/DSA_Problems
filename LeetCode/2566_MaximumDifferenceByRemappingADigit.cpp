#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

class Solution
{
public:
    int minMaxDifference(int num)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string t = to_string(num);
        int index = -1, index2 = -1;
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != '9' && index == -1)
            {
                index = i;
            }
            if (t[i] != 0 && index2 == -1)
            {
                index2 = i;
            }
        }
        int maxVal = num;
        int minVal = num;
        if (index != -1)
        {
            char maxi = t[index];
            string currMaxi = t;
            for (int i = 0; i < t.length(); i++)
            {
                if (currMaxi[i] == maxi)
                {
                    currMaxi[i] = '9';
                }
            }
            maxVal = stoi(currMaxi);
        }
        if (index2 != -1)
        {
            char maxi = t[index2];
            string currMaxi = t;
            for (int i = 0; i < t.length(); i++)
            {
                if (currMaxi[i] == maxi)
                {
                    currMaxi[i] = '0';
                }
            }
            minVal = stoi(currMaxi);
        }
        return maxVal - minVal;
    }
};