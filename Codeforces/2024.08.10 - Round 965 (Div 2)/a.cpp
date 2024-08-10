#include <bits/stdc++.h>
using namespace std;

/*
A. Find K Distinct Points with Fixed Center
time limit per test1 second
memory limit per test256 megabytes
I couldn't think of a good title for this problem, so I decided to learn from LeetCode.
— Sun Tzu, The Art of War
You are given three integers xc, yc, and k (−100≤xc,yc≤100, 1≤k≤1000).

You need to find k distinct points (x1,y1), (x2,y2), …, (xk,yk), having integer coordinates, on the 2D coordinate plane such that:

their center∗
 is (xc,yc)−109≤xi,yi≤109 for all i from 1 to k
 It can be proven that at least one set of k distinct points always exists that satisfies these conditions.

∗
The center of k points (x1,y1), (x2,y2), …, (xk,yk) is (x1+x2+…+xkk,y1+y2+…+ykk).

Input
The first line contains t (1≤t≤100) — the number of test cases.

Each test case contains three integers xc, yc, and k (−100≤xc,yc≤100, 1≤k≤1000) — the coordinates of the center and the number of distinct points you must output.

It is guaranteed that the sum of k over all test cases does not exceed 1000.

Output
For each test case, output k lines, the i-th line containing two space separated integers, xi and yi, (−109≤xi,yi≤109) — denoting the position of the i-th point.

If there are multiple answers, print any of them. It can be shown that a solution always exists under the given constraints.
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
        int x, y, k;
        cin >> x >> y >> k;

        vii ans;
        if (k % 2 == 1)
        {
            ans.pb({x, y});
            k--;
        }
        for (int i = 1; i <= k / 2; i++)
        {
            ans.pb({x + i, y + i});
            ans.pb({x - i, y - i});
        }
        for (auto &i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}