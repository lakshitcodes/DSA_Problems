#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/fraction-addition-and-subtraction/

class Solution
{
public:
    long long findGCD(long long a, long long b)
    {
        while (b != 0)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void printVec(vector<pair<int, int>> &result)
    {
        for (auto &i : result)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    vector<pair<int, int>> convertToFractions(string exp)
    {
        vector<pair<int, int>> result;
        int n = exp.size();
        int i = 0;
        while (i < n)
        {
            int sign = 1;
            if (exp[i] == '-')
            {
                sign = -1;
                i++;
            }
            else if (exp[i] == '+')
            {
                i++;
            }
            int num = 0;

            while (i < n && isdigit(exp[i]))
            {
                num = num * 10 + exp[i] - '0';
                i++;
            }
            int den = 0;
            i++;
            while (i < n && isdigit(exp[i]))
            {
                den = den * 10 + exp[i] - '0';
                i++;
            }
            result.push_back({num * sign, den});
        }
        printVec(result);
        return result;
    }
    pair<int, int> addFractions(pair<int, int> &a, pair<int, int> &b)
    {
        long long denominator = a.second * b.second;
        long long numerator = a.first * b.second + a.second * b.first;
        long long gcd = findGCD(abs(numerator), denominator);
        return {numerator / gcd, denominator / gcd};
    }
    string fractionAddition(string expression)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<pair<int, int>> fractions = convertToFractions(expression);
        pair<int, int> ans = {0, 1};
        for (auto &i : fractions)
        {
            ans = addFractions(ans, i);
        }
        string result = to_string(ans.first) + '/' + to_string(ans.second);
        return result;
    }
};