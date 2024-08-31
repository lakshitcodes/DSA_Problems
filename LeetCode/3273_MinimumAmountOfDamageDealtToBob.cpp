#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/

class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            double first = (double)a.first / a.second;
            double second = (double)b.first / b.second;

            return first == second ? a.first < b.first : first < second;
        }
    };
    long long minDamage(int power, vector<int> &damage, vector<int> &health)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        int totalDamage = 0;
        for (int i = 0; i < damage.size(); i++)
        {
            pq.push({damage[i], health[i]});
            totalDamage += damage[i];
        }
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            cout << front.first << endl;
            int time = ceil((double)front.second / power);
            ans += totalDamage * time;
            totalDamage -= front.first;
        }
        return ans;
    }
};