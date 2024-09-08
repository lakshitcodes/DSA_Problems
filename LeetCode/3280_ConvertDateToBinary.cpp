#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/convert-date-to-binary/description/

class Solution
{
public:
    string convertDateToBinary(string date)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string ans = "";
        string temp = "";
        int count = 0;
        for (int i = 0; i < date.size(); i++)
        {
            while (i < date.size() && date[i] != '-')
            {
                temp += date[i];
                i++;
            }
            ans += toBinary(stoi(temp));
            if (count <= 1)
            {
                ans += '-';
                count++;
            }
            temp.clear();
        }
        return ans;
    }

private:
    string toBinary(int num)
    {
        string binary = "";
        while (num > 0)
        {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }
};