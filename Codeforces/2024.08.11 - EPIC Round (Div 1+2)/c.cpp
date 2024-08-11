#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
C. Black Circles
time limit per test2 seconds
memory limit per test256 megabytes
There are n circles on a two-dimensional plane. The i-th circle is centered at (xi,yi). Initially, all circles have a radius of 0.

The circles' radii increase at a rate of 1 unit per second.

You are currently at (xs,ys); your goal is to reach (xt,yt) without touching the circumference of any circle (including the moment you reach (xt,yt)). You can move in any direction you want. However, your speed is limited to 1 unit per second.

Please determine whether this is possible.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤105) — the number of circles.

The next n lines each contain two integers xi, yi (1≤xi,yi≤109) — the center of each circle.

The final line contains four integers xs, ys, xt, yt (1≤xs,ys,xt,yt≤109) — the coordinates of the starting point and the goal, respectively.

It is guaranteed that these n+2 points are distinct.

It is guaranteed that the sum of n over all testcases does not exceed 105.

Output
For each test case, output YES if it is possible to reach the goal without touching the circle boundaries, and output NO otherwise.

You can output Yes and No in any case (for example, strings yEs, yes, Yes, and YES will be recognized as a positive response).
*/

#define ll long long
#define pb push_back
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define take(arr)       \
    for (auto &i : arr) \
        cin >> i;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<pair<ll, ll>> circles(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> circles[i].first >> circles[i].second;
        }

        ll xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;
        ll time = (dist(xs, ys, xt, yt));
        bool poss = true;
        for (ll i = 0; i < n; i++)
        {
            if (time >= dist(circles[i].first, circles[i].second, xt, yt))
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
