#include <bits/stdc++.h>
using namespace std;

/*
B. Index and Maximum Value
time limit per test1 second
memory limit per test256 megabytes
After receiving yet another integer array a1,a2,…,an at her birthday party, Index decides to perform some operations on it.

Formally, there are m operations that she is going to perform in order. Each of them belongs to one of the two types:

+ l r. Given two integers l and r, for all 1≤i≤n such that l≤ai≤r, set ai:=ai+1.- l r. Given two integers l and r, for all 1≤i≤n such that l≤ai≤r, set ai:=ai−1.
For example, if the initial array a=[7,1,3,4,3], after performing the operation + 2 4, the array a=[7,1,4,5,4]. Then, after performing the operation - 1 10, the array a=[6,0,3,4,3].

Index is curious about the maximum value in the array a. Please help her find it after each of the m operations.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤2⋅104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n and m (1≤n≤105, 1≤m≤105) — the length of the array and the number of operations.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the initial array a.

Then m lines follow, each line corresponds to the operation, in the following format: c l r (c∈{+,-}, l and r are integers, 1≤l≤r≤109) — the description of the operation.

Note that the elements ai may not satisfy 1≤ai≤109 after some operations, as it is shown in the example.

It is guaranteed that the sum of n over all test cases does not exceed 105, and the sum of m over all test cases does not exceed 105.

Output
For each test case, output one single line containing m integers, with the i-th of them describing the maximum value of the array after the i
-th operation.
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
        int n, m;
        cin >> n >> m;
        vll arr(n);
        ll maxi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(arr[i], maxi);
        }
        for (int i = 0; i < m; i++)
        {
            char c;
            cin >> c;
            int start, end;
            cin >> start >> end;
            if (c == '+')
            {
                if (maxi >= start && maxi <= end)
                {
                    maxi += 1;
                }
            }
            else
            {
                if (maxi >= start && maxi <= end)
                {
                    maxi -= 1;
                }
            }
            cout << maxi << " ";
        }
        cout << endl;
    }
    return 0;
}