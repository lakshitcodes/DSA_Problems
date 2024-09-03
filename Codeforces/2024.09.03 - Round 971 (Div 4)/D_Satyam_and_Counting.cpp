#include <bits/stdc++.h>
using namespace std;

/*
D. Satyam and Counting
time limit per test2 seconds
memory limit per test256 megabytes
Satyam is given n
 distinct points on the 2D coordinate plane. It is guaranteed that 0≤yi≤1
 for all given points (xi,yi)
. How many different nondegenerate right triangles∗
 can be formed from choosing three different points as its vertices?

Two triangles a
 and b
 are different if there is a point v
 such that v
 is a vertex of a
 but not a vertex of b
.

∗
A nondegenerate right triangle has positive area and an interior 90∘ angle.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains an integer n (3≤n≤2⋅105) — the number of points.

The following n lines contain two integers xi and yi (0≤xi≤n, 0≤yi≤1) — the i'th point that Satyam can choose from. It is guaranteed that all (xi,yi) are pairwise distinct.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
Output an integer for each test case, the number of distinct nondegenerate right triangles that can be formed from choosing three points.
*/

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define take(arr)       \
    for (auto &i : arr) \
        cin >> i;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> zeroes, ones;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y == 0)
            {
                zeroes.insert(x);
            }
            else
            {
                ones.insert(x);
            }
        }
        ll answer = 0;

        for (int num : zeroes)
        {
            if (ones.find(num) != ones.end())
            {
                answer += n - 2;
            }
        }

        for (int num : zeroes)
        {
            if (ones.find(num - 1) != ones.end() and ones.find(num + 1) != ones.end())
            {
                answer += 1;
            }
        }

        for (int num : ones)
        {
            if (zeroes.find(num - 1) != zeroes.end() and zeroes.find(num + 1) != zeroes.end())
            {
                answer += 1;
            }
        }
        std::cout << answer << endl;
    }
    return 0;
}