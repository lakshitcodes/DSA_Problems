#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/24-game/

class Solution
{
public:
    bool solve(vector<double> &cards)
    {
        if (cards.size() == 1)
        {
            return abs(cards[0] - 24) <= 1e-6;
        }
        for (int i = 0; i < cards.size(); i++)
        {
            for (int j = i + 1; j < cards.size(); j++)
            {
                vector<double> curr;
                for (int k = 0; k < cards.size(); k++)
                {
                    if (i != k && j != k)
                    {
                        curr.push_back(cards[k]);
                    }
                }
                curr.push_back(cards[i] + cards[j]);
                if (solve(curr))
                {
                    return true;
                }
                curr.back() = (cards[i] - cards[j]);
                if (solve(curr))
                {
                    return true;
                }
                curr.back() = (cards[i] * cards[j]);
                if (solve(curr))
                {
                    return true;
                }
                if (cards[j] != 0)
                {
                    curr.back() = (cards[i] / cards[j]);
                    if (solve(curr))
                    {
                        return true;
                    }
                }
                if (cards[i] != 0)
                {
                    curr.back() = (cards[j] / cards[i]);
                    if (solve(curr))
                    {
                        return true;
                    }
                }
                curr.back() = (cards[j] - cards[i]);
                if (solve(curr))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int> &cards)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<double> dCards;
        for (auto &i : cards)
        {
            dCards.push_back((double)(i));
        }
        return solve(dCards);
    }
};