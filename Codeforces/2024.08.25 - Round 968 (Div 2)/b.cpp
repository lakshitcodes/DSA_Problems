#include <bits/stdc++.h>
using namespace std;

/*
B. Turtle and Piggy Are Playing a Game 2
time limit per test1 second
memory limit per test256 megabytes
Turtle and Piggy are playing a game on a sequence. They are given a sequence a1,a2,…,an, and Turtle goes first. Turtle and Piggy alternate in turns (so, Turtle does the first turn, Piggy does the second, Turtle does the third, etc.).

The game goes as follows:

Let the current length of the sequence be m. If m=1, the game ends.
If the game does not end and it's Turtle's turn, then Turtle must choose an integer i such that 1≤i≤m−1, set ai to max(ai,ai+1), and remove ai+1.
If the game does not end and it's Piggy's turn, then Piggy must choose an integer i such that 1≤i≤m−1, set ai to min(ai,ai+1), and remove ai+1.
Turtle wants to maximize the value of a1 in the end, while Piggy wants to minimize the value of a1 in the end. Find the value of a1 in the end if both players play optimally.

You can refer to notes for further clarification.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤105) — the length of the sequence.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤105) — the elements of the sequence a.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, output a single integer — the value of a1 in the end if both players play optimally.
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
        vi arr(n);
        take(arr);
        sort(arr.begin(), arr.end());

        cout << arr[n / 2] << endl;
    }
    return 0;
}