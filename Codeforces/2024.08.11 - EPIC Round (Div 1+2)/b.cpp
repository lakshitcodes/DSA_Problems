#include <bits/stdc++.h>
using namespace std;

/*
B. Removals Game
time limit per test1 second
memory limit per test256 megabytes
Alice got a permutation a1,a2,…,an of [1,2,…,n], and Bob got another permutation b1,b2,…,bn of [1,2,…,n]. They are going to play a game with these arrays.

In each turn, the following events happen in order:

Alice chooses either the first or the last element of her array and removes it from the array;
Bob chooses either the first or the last element of his array and removes it from the array.
The game continues for n−1 turns, after which both arrays will have exactly one remaining element: x in the array a and y in the array b.

If x=y, Bob wins; otherwise, Alice wins. Find which player will win if both players play optimally.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤3⋅105).

The next line contains n integers a1,a2,…,an (1≤ai≤n, all ai are distinct) — the permutation of Alice.

The next line contains n integers b1,b2,…,bn (1≤bi≤n, all bi are distinct) — the permutation of Bob.

It is guaranteed that the sum of all n does not exceed 3⋅105.

Output
For each test case, print a single line with the name of the winner, assuming both players play optimally. If Alice wins, print Alice; otherwise, print Bob.
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
        int n, check;
        check = 1;
        cin >> n;
        vi a(n + 1), b(n + 1), c(n + 10);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            c[n - i + 1] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (b[i] != a[i])
            {
                check = 0;
            }
        }
        if (check == 0)
        {
            check = 1;
            for (int i = 1; i <= n; i++)
            {
                if (b[i] != c[i])
                {
                    check = 0;
                }
            }
        }
        if (check)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }
    }
    return 0;
}