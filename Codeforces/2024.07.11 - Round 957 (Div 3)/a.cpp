#include <bits/stdc++.h>
using namespace std;
/*
A. Only Pluses
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kmes has written three integers a, b and c in order to remember that he has to give Noobish_Monk a×b×c bananas.

Noobish_Monk has found these integers and decided to do the following at most 5 times:
pick one of these integers; increase it by 1.
For example, if a=2, b=3 and c=4, then one can increase a three times by one and increase b two times. After that a=5, b=5, c=4. Then the total number of bananas will be 5×5×4=100.

What is the maximum value of a×b×c Noobish_Monk can achieve with these operations?

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains three integers a, b and c (1≤a,b,c≤10) — Kmes's integers.

Output
For each test case, output a single integer — the maximum amount of bananas Noobish_Monk can get.
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(x);
        pq.push(y);
        pq.push(z);
        for (int i = 1; i <= 5; i++)
        {
            long long ele = pq.top();
            pq.pop();
            pq.push(ele + 1);
        }
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        z = pq.top();
        pq.pop();
        cout << x * y * z << endl;
    }

    return 0;
}