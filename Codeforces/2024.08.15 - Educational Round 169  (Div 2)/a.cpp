#include <bits/stdc++.h>
using namespace std;

/*
A. Closest Point
time limit per test2 seconds
memory limit per test512 megabytes
Consider a set of points on a line. The distance between two points i and j is |i−j|.

The point i from the set is the closest to the point j from the set, if there is no other point k in the set such that the distance from j to k is strictly less than the distance from j to i. In other words, all other points from the set have distance to j
 greater or equal to |i−j|.

For example, consider a set of points {1,3,5,8}:

for the point 1, the closest point is 3 (other points have distance greater than |1−3|=2);
for the point 3, there are two closest points: 1 and 5;
for the point 5, the closest point is 3 (but not 8, since its distance is greater than |3−5|);
for the point 8, the closest point is 5.
You are given a set of points. You have to add an integer point into this set in such a way that it is different from every existing point in the set, and it becomes the closest point to every point in the set. Is it possible?

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer n (2≤n≤40) — the number of points in the set;
the second line contains n integers x1,x2,…,xn (1≤x1<x2<⋯<xn≤100) — the points from the set.
Output
For each test case, print YES if it is possible to add a new point according to the conditions from the statement. Otherwise, print NO.
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
        vector<int> points(n);

        for (int i = 0; i < n; i++)
        {
            cin >> points[i];
        }
        if (n > 2)
        {
            cout << "NO\n";
        }
        else
        {
            if (n == 1)
            {
                cout << "NO\n";
            }
            else
            {
                int diff = abs(points[1] - points[0]);
                cout << (diff > 1 ? "YES" : "NO") << endl;
            }
        }
    }
    return 0;
}