#include <iostream>
#include <vector>
using namespace std;

/*
C. Boring Day
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
On another boring day, Egor got bored and decided to do something. But since he has no friends, he came up with a game to play.

Egor has a deck of n cards, the i-th card from the top has a number ai written on it. Egor wants to play a certain number of rounds until the cards run out. In each round, he takes a non-zero number of cards from the top of the deck and finishes the round. If the sum of the numbers on the cards collected during the round is between l
 and r, inclusive, the round is won; otherwise, it is lost.

Egor knows by heart the order of the cards. Help Egor determine the maximum number of rounds he can win in such a game. Note that Egor is not required to win rounds consecutively.

Input
Each test consists of several test cases. The first line contains an integer t (1≤t≤104) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains three integers n, l, and r (1≤n≤105, 1≤l≤r≤109).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the numbers on the cards from top to bottom.

It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

Output
For each test case, output a single number — the maximum number of rounds Egor can win.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int maxRounds = 0;
        long long currentSum = 0;
        int start = 0;

        for (int end = 0; end < n; ++end)
        {
            currentSum += a[end];

            while (currentSum > r && start <= end)
            {
                currentSum -= a[start];
                start++;
            }

            if (currentSum >= l && currentSum <= r)
            {
                maxRounds++;
                currentSum = 0;
                start = end + 1;
            }
        }

        cout << maxRounds << endl;
    }

    return 0;
}
