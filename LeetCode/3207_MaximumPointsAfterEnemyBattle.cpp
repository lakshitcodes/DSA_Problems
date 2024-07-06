#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-points-after-enemy-battles/

class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (currentEnergy == 0)
        {
            return 0;
        }
        sort(enemyEnergies.begin(), enemyEnergies.end());
        vector<bool> visited(enemyEnergies.size(), false);
        long long points = 0;
        if (currentEnergy < enemyEnergies[0])
        {
            return 0;
        }
        int i = 0;
        int j = enemyEnergies.size() - 1;
        while (i <= j)
        {
            if (visited[i])
            {
                i++;
            }
            if (currentEnergy >= enemyEnergies[i])
            {
                int enemiesDefeated = currentEnergy / enemyEnergies[i];
                currentEnergy -= enemiesDefeated * enemyEnergies[i];
                points += enemiesDefeated;
            }
            if (points)
            {
                currentEnergy += enemyEnergies[j];
                visited[j] = true;
                j--;
            }
        }
        return points;
    }
};