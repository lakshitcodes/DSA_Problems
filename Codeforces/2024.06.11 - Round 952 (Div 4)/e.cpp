#include <bits/stdc++.h>
using namespace std;

/*
E. Secret Box
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ntarsis has a box B with side lengths x, y, and z. It lies in the 3D coordinate plane, extending from (0,0,0) to (x,y,z).

Ntarsis has a secret box S. He wants to choose its dimensions such that all side lengths are positive integers, and the volume of S is k. He can place S somewhere within B such that:
S is parallel to all axes.every corner of S lies on an integer coordinate.
S is magical, so when placed at an integer location inside B, it will not fall to the ground.

Among all possible ways to choose the dimensions of S, determine the maximum number of distinct locations he can choose to place his secret box S
 inside B. Ntarsis does not rotate S once its side lengths are selected.

Input
The first line consists of an integer t, the number of test cases (1≤t≤2000). The description of the test cases follows.

The first and only line of each test case contains four integers x,y,z and k (1≤x,y,z≤2000, 1≤k≤x⋅y⋅z).

It is guaranteed the sum of all x, sum of all y, and sum of all z do not exceed 2000 over all test cases.

Note that k may not fit in a standard 32-bit integer data type.

Output
For each test case, output the answer as an integer on a new line. If there is no way to select the dimensions of S so it fits in B, output 0.
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long t;
    cin >> t;
    while (t--)
    {
        long long x, y, z;
        long long k;
        cin >> x >> y >> z >> k;

        long long max_placements = 0;

        for (long long a = 1; a <= x; ++a)
        {
            if (k % a == 0)
            {
                for (long long b = 1; b <= y; ++b)
                {
                    if (k % (a * b) == 0)
                    {
                        long long c = k / (a * b);
                        if (c <= z)
                        {
                            long long placements = (x - a + 1) * (y - b + 1) * (z - c + 1);
                            max_placements = max(max_placements, placements);
                        }
                    }
                }
            }
        }

        cout << max_placements << endl;
    }

    return 0;
}
