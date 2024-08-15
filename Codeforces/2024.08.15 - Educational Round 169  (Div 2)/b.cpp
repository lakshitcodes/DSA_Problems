#include <iostream>
using namespace std;

/*

B. Game with Doors
time limit per test2 seconds
memory limit per test256 megabytes
There are 100 rooms arranged in a row and 99 doors between them; the i-th door connects rooms i and i+1. Each door can be either locked or unlocked. Initially, all doors are unlocked.

We say that room x is reachable from room y if all doors between them are unlocked.
You know that:
Alice is in some room from the segment [l,r];
Bob is in some room from the segment [L,R];
Alice and Bob are in different rooms.
However, you don't know the exact rooms they are in.

You don't want Alice and Bob to be able to reach each other, so you are going to lock some doors to prevent that. What's the smallest number of doors you have to lock so that Alice and Bob cannot meet, regardless of their starting positions inside the given segments?

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains two integers l and r (1≤l<r≤100) — the bounds of the segment of rooms where Alice is located.

The second line of each test case contains two integers L and R (1≤L<R≤100) — the bounds of the segment of rooms where Bob is located.

Output
For each test case, print a single integer — the smallest number of doors you have to lock so that Alice and Bob cannot meet, regardless of their starting positions inside the given segments.*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l, r, L, R;
        cin >> l >> r >> L >> R;

        if (r < L)
        {
            cout << 1 << endl;
        }
        else if (R < l)
        {
            cout << 1 << endl;
        }
        else
        {
            if (l == L && r == R)
            {
                cout << r - l << endl;
            }
            else if (l < L && r > R)
            {
                cout << R - L + 2 << endl;
            }
            else if (L < l && R > r)
            {
                cout << r - l + 2 << endl;
            }
            else if (l == L || r == R)
            {
                cout << min(r, R) - max(l, L) + 1 << endl;
            }
            else
            {
                cout << min(r, R) - max(l, L) + 2 << endl;
            }
        }
    }

    return 0;
}
