#include <bits/stdc++.h>
using namespace std;

// Question Link : https://codeforces.com/contest/1983/problem/C

/*
C. Have Your Cake and Eat It Too
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice, Bob and Charlie want to share a rectangular cake cut into n pieces. Each person considers every piece to be worth a different value. The i-th piece is considered to be of value ai by Alice, bi by Bob and ci by Charlie.

The sum over all ai, all bi and all ci individually is the same, equal to tot.

Given the values of each piece of the cake for each person, you need to give each person a contiguous slice of cake. In other words, the indices at the left and right ends of these subarrays (the slices given to each person) can be represented as (la,ra), (lb,rb) and (lc,rc) respectively for Alice, Bob and Charlie. The division needs to satisfy the following constraints:

No piece is assigned to more than one person, i.e., no two subarrays among [la,…,ra], [lb,…,rb] and [lc,…,rc] intersect.∑rai=laai,∑rbi=lbbi,∑rci=lcci≥⌈tot3⌉
.
Here, the notation ⌈ab⌉ represents ceiling division. It is defined as the smallest integer greater than or equal to the exact division of a by b. In other words, it rounds up the division result to the nearest integer. For instance ⌈103⌉=4 and ⌈153⌉=5.

Input
The first line contains an integer t, the number of testcases, (1≤t≤104)

For each testcase:

The first line contains the integer n (3≤n≤2⋅105).

The following three lines contain n integers each:

One line with n integers a1,a2,…,an represents the values for Alice (1≤ai≤106).

The next line with n integers b1,b2,…,bn represents the values for Bob (1≤bi≤106).

The next line with n integers c1,c2,…,cn represents the values for Charlie (1≤ci≤106).

It is guaranteed that ∑ni=1ai=∑ni=1bi=∑ni=1ci.

The sum of n over all testcases does not exceed 2⋅105.
Output
For each testcase, output −1 if the required condition is impossible.

Otherwise, output six numbers – la,ra,lb,rb,lc,rc, the respective starting and ending indices (1-indexed) of the subarrays for Alice, Bob and Charlie, respectively.
*/

vector<int> helper(vector<int> a, vector<int> b, vector<int> c, long long sum)
{
    int n = a.size();

    long long v = ceil((long double)(sum) / 3);

    vector<int> z(6, -1);
    vector<int> x(6);

    int i = 0;

    long long y = 0;
    while (i < n && y < v)
    {
        y += a[i];
        i++;
    }
    if (i >= n)
        return z;

    x[0] = 0;
    x[1] = i - 1;

    y = 0;
    x[2] = i;

    while (i < n && y < v)
    {
        y += b[i];
        i++;
    }
    if (i >= n)
        return z;
    x[3] = i - 1;

    y = 0;
    x[4] = i;

    while (i < n && y < v)
    {
        y += c[i];
        i++;
    }
    if (y < v)
        return z;
    x[5] = i - 1;

    return x;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
            cin >> c[i];

        long long sum = 0;

        for (int x : a)
            sum += x;

        vector<int> e = helper(a, b, c, sum);
        vector<int> f = helper(a, c, b, sum);
        vector<int> g = helper(b, a, c, sum);
        vector<int> h = helper(b, c, a, sum);
        vector<int> i = helper(c, a, b, sum);
        vector<int> j = helper(c, b, a, sum);

        // cout<<sum/3<<endl;

        if (e[0] != -1)
            cout << e[0] + 1 << " " << e[1] + 1 << " " << e[2] + 1 << " " << e[3] + 1 << " " << e[4] + 1 << " " << e[5] + 1 << endl;
        else if (f[0] != -1)
            cout << f[0] + 1 << " " << f[1] + 1 << " " << f[4] + 1 << " " << f[5] + 1 << " " << f[2] + 1 << " " << f[3] + 1 << endl;
        else if (g[0] != -1)
            cout << g[2] + 1 << " " << g[3] + 1 << " " << g[0] + 1 << " " << g[1] + 1 << " " << g[4] + 1 << " " << g[5] + 1 << endl;
        else if (h[0] != -1)
            cout << h[4] + 1 << " " << h[5] + 1 << " " << h[0] + 1 << " " << h[1] + 1 << " " << h[2] + 1 << " " << h[3] + 1 << endl;
        else if (i[0] != -1)
            cout << i[2] + 1 << " " << i[3] + 1 << " " << i[4] + 1 << " " << i[5] + 1 << " " << i[0] + 1 << " " << i[1] + 1 << endl;
        else if (j[0] != -1)
            cout << j[4] + 1 << " " << j[5] + 1 << " " << j[2] + 1 << " " << j[3] + 1 << " " << j[0] + 1 << " " << j[1] + 1 << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}