#include <bits/stdc++.h>
using namespace std;

/*
D1. Turtle and a MEX Problem (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
The two versions are different problems. In this version of the problem, you can choose the same integer twice or more. You can make hacks only if both versions are solved.

One day, Turtle was playing with n sequences. Let the length of the i-th sequence be li. Then the i-th sequence was ai,1,ai,2,…,ai,li.

Piggy gave Turtle a problem to solve when Turtle was playing. The statement of the problem was:

There was a non-negative integer x at first. Turtle would perform an arbitrary number (possibly zero) of operations on the integer.
In each operation, Turtle could choose an integer i such that 1≤i≤n, and set x to mex†(x,ai,1,ai,2,…,ai,li).
Turtle was asked to find the answer, which was the maximum value of x after performing an arbitrary number of operations.Turtle solved the above problem without difficulty. He defined f(k) as the answer to the above problem when the initial value of x was k.

Then Piggy gave Turtle a non-negative integer m and asked Turtle to find the value of ∑i=0mf(i) (i.e., the value of f(0)+f(1)+…+f(m)). Unfortunately, he couldn't solve this problem. Please help him!

†mex(c1,c2,…,ck) is defined as the smallest non-negative integer x which does not occur in the sequence c. For example, mex(2,2,0,3) is 1, mex(1,2) is 0.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains two integers n,m (1≤n≤2⋅105,0≤m≤109).

Each of the following n lines contains several integers. The first integer li (1≤li≤2⋅105) represents the length of the i-th sequence, and the following li integers ai,1,ai,2,…,ai,li (0≤ai,j≤109) represent the elements of the i-th sequence.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105, and the sum of ∑li over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer — the value of ∑i=0mf(i).
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

long long sum(long long num)
{
    return num * (num + 1) / 2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        ll maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int len;
            cin >> len;
            set<int> st;
            for (int k = 0; k < len; k++)
            {
                int a;
                cin >> a;
                st.insert(a);
            }
            ll mex;
            bool flag = true;
            for (int j = 0;; j++)
            {
                if (!st.count(j))
                {
                    if (flag)
                    {
                        flag = false;
                    }
                    else
                    {
                        mex = j;
                        break;
                    }
                }
            }
            maxi = max(maxi, mex);
        }
        if (maxi >= m)
        {
            cout << maxi * (m + 1) << endl;
        }
        else
        {
            cout << sum(maxi) + sum(m) << endl;
        }
    }
    return 0;
}