#include <bits/stdc++.h>
using namespace std;

/*
E. Triple Operations
time limit per test1 second
memory limit per test256 megabytes
On the board Ivy wrote down all integers from l to r, inclusive.

In an operation, she does the following:

pick two numbers x and y on the board, erase them, and in their place write the numbers 3x and ⌊y3⌋. (Here ⌊∙⌋ denotes rounding down to the nearest integer).What is the minimum number of operations Ivy needs to make all numbers on the board equal 0
? We have a proof that this is always possible.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The only line of each test case contains two integers l and r (1≤l<r≤2⋅105).

Output
For each test case, output a single integer — the minimum number of operations needed to make all numbers on the board equal 0.
*/

#define ll long long
#define mod 1000000007

int nextPowerOf3(int x)
{
    int power = 1;
    while (power <= x)
    {
        power *= 3;
    }
    return power;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        ll sum = 0;

        int current = a;
        int smallPower = -1;
        while (current <= b)
        {

            int power = 1;
            while (power <= current)
            {
                power *= 3;
            }

            int nextBoundary = power - 1;

            if (nextBoundary > b)
            {
                nextBoundary = b;
            }

            int count = nextBoundary - current + 1;

            int currentPower = log2(power) / log2(3);
            if (smallPower == -1)
            {
                smallPower = currentPower;
            }
            sum += count * currentPower;
            sum %= mod;
            current = nextBoundary + 1;
        }

        cout << (sum + smallPower) % mod << endl;
    }

    return 0;
}
