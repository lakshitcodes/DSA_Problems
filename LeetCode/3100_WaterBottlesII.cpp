#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/water-bottles-ii/

class Solution
{
public:
    int maxBottlesDrunk(int numBottle, int numExchange)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int bottleDrunk = 0;
        int emptyBottle = 0;
        while (numBottle != 0)
        {
            bottleDrunk += numBottle;
            emptyBottle += numBottle;
            numBottle = 0;
            while (emptyBottle >= numExchange)
            {
                numBottle++;
                emptyBottle -= numExchange++;
            }
        }
        return bottleDrunk;
    }
};