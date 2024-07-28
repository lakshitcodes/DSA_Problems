#include <iostream>
#include <vector>
using namespace std;

/*
B. AND Reconstruction
time limit per test1 second
memory limit per test256 megabytes
You are given an array b of n−1 integers.

An array a of n integers is called good if bi=ai&ai+1 for 1≤i≤n−1, where & denotes the bitwise AND operator.

Construct a good array, or report that no good arrays exist.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n (2≤n≤105) — the length of the array a.

The second line of each test case contains n−1 integers b1,b2,…,bn−1 (0≤bi<230) — the elements of the array b.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, output a single integer −1 if no good arrays exist.

Otherwise, output n space-separated integers a1,a2,…,an (0≤ai<230) — the elements of a good array a.

If there are multiple solutions, you may output any of them.
*/

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> b[i];
        }

        vector<int> a(n, 0);
        bool valid = true;

        a[0] = b[0];

        for (int i = 1; i < n - 1; ++i)
        {
            a[i] = b[i] | b[i - 1];
        }
        a[n - 1] = b[n - 2];

        for (int i = 0; i < n - 1; ++i)
        {
            if ((a[i] & a[i + 1]) != b[i])
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
