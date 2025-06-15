#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

class Solution
{
public:
    int maxDiff(int num)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string numStr = to_string(num);
        set<char> uniqueDigits(numStr.begin(), numStr.end());
        int maxVal = num, minVal = num;

        for (char digit : uniqueDigits)
        {
            for (char newDigit = '0'; newDigit <= '9'; ++newDigit)
            {
                if (numStr[0] == digit && newDigit == '0')
                    continue;
                string newNumStr = numStr;
                replace(newNumStr.begin(), newNumStr.end(), digit, newDigit);
                int newNum = stoi(newNumStr);
                maxVal = max(maxVal, newNum);
                minVal = min(minVal, newNum);
            }
        }

        return maxVal - minVal;
    }
};