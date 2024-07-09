#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/expression-add-operators/

class Solution
{
public:
    void solve(int index, string currPath, long long sum, long long prev, string num,
               int target, vector<string> &ans)
    {
        if (index == num.size())
        {
            if (sum == target)
            {
                ans.push_back(currPath);
            }
            return;
        }
        for (int j = index; j < num.size(); j++)
        {
            if (j > index && num[index] == '0')
            {
                break;
            }
            string currNum = num.substr(index, j - index + 1);
            long long number = stoll(currNum);
            if (index == 0)
            {
                solve(j + 1, currNum, number, number, num, target, ans);
            }
            else
            {
                solve(j + 1, currPath + '+' + currNum, sum + number, number, num, target, ans);
                solve(j + 1, currPath + '-' + currNum, sum - number, -number, num, target, ans);
                solve(j + 1, currPath + '*' + currNum, sum - prev + (prev * number), prev * number, num, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<string> ans;
        if (num.empty())
            return ans;
        solve(0, "", 0, 0, num, target, ans);
        return ans;
    }
};
