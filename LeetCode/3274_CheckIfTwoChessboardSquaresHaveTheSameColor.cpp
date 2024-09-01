#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/

class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        auto getColor = [](const std::string &coord)
        {
            int column = coord[0] - 'a' + 1;
            int row = coord[1] - '0';
            return (column + row) % 2;
        };

        return getColor(coordinate1) == getColor(coordinate2);
    }
};