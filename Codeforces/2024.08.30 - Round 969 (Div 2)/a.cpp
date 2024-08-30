#include <bits/stdc++.h>
using namespace std;

/*
A. Dora's Set
time limit per test1 second
memory limit per test256 megabytes
Dora has a set s containing integers. In the beginning, she will put all integers in [l,r] into the set s. That is, an integer x is initially contained in the set if and only if l≤x≤r. Then she allows you to perform the following operations:

Select three distinct integers a, b, and c from the set s, such that gcd(a,b)=gcd(b,c)=gcd(a,c)=1†.
Then, remove these three integers from the set s.
What is the maximum number of operations you can perform?
†
Recall that gcd(x,y) means the greatest common divisor of integers x and y.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers l and r (1≤l≤r≤1000) — the range of integers in the initial set.

Output
For each test case, output a single integer — the maximum number of operations you can perform.
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
        int l, r;
        cin >> l >> r;
        if (l % 2 == 0)
        {
            l += 1;
        }
        cout << (r - l + 2) / 4 << endl;
    }
    return 0;
}