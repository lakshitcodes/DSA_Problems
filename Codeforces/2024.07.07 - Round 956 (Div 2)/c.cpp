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

vector<int> findVertex(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int tot = accumulate(a.begin(), a.end(), 0);
    int n = a.size();
    int value = ceil((double)tot / 3);
    vector<int> ans(6, -1);
    int l1, l2, l3, r1, r2, r3;
    l1 = l2 = l3 = r1 = r2 = r3 = 0;
    int curr = 0;
    while (curr < value && r1 < n)
    {
        curr += a[r1];
        r1++;
    }
    if (curr < value)
    {
        return ans;
    }
    curr = 0;
    l2 = r1;
    r2 = l2;
    while (curr < value && r2 < n)
    {
        curr += b[r2];
        r2++;
    }
    if (curr < value)
    {
        return ans;
    }
    curr = 0;
    l3 = r2;
    r3 = l3;
    while (curr < value && r3 < n)
    {
        curr += c[r3];
        r3++;
    }
    if (r3 < n)
    {
        r3 = n;
    }
    if (curr < value)
    {
        return ans;
    }
    return {l1 + 1, r1, l2 + 1, r2, l3 + 1, r3};
}

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
        vector<int> a(n), b(n), c(n);
        for (auto &i : a)
        {
            cin >> i;
        }
        for (auto &i : b)
        {
            cin >> i;
        }
        for (auto &i : c)
        {
            cin >> i;
        }
        vector<int> ans;

        ans = findVertex(a, b, c);
        if (ans[0] != -1)
        {

            for (auto i : ans)
            {
                cout << i << ' ';
            }
            cout << endl;
            continue;
        }

        ans = findVertex(a, c, b);
        if (ans[0] != -1)
        {

            cout << ans[0] << " " << ans[1] << ' ' << ans[4] << ' ' << ans[5] << ' ' << ans[2] << " " << ans[3] << endl;
            continue;
        }

        ans = findVertex(b, a, c);
        if (ans[0] != -1)
        {

            cout << ans[2] << " " << ans[3] << ' ' << ans[0] << ' ' << ans[1] << ' ' << ans[4] << " " << ans[5] << endl;
            continue;
        }

        ans = findVertex(b, c, a);
        if (ans[0] != -1)
        {

            cout << ans[4] << " " << ans[5] << ' ' << ans[0] << ' ' << ans[1] << " " << ans[2] << " " << ans[3] << endl;
            continue;
        }

        ans = findVertex(c, a, b);
        if (ans[0] != -1)
        {

            cout << ans[2] << ' ' << ans[3] << " " << ans[4] << " " << ans[5] << ' ' << ans[0] << " " << ans[1] << endl;
            continue;
        }

        ans = findVertex(c, b, a);
        if (ans[0] != -1)
        {

            cout << ans[4] << ' ' << ans[5] << " " << ans[0] << " " << ans[1] << ' ' << ans[2] << " " << ans[3] << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}
