#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
A. Strange Splitting
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Define the range of a non-empty array to be the maximum value minus the minimum value. For example, the range of [1,4,2] is 4−1=3.

You are given an array a1,a2,…,an of length n≥3. It is guaranteed a is sorted.

You have to color each element of a red or blue so that:

the range of the red elements does not equal the range of the blue elements, and there is at least one element of each color.
If there does not exist any such coloring, you should report it. If there are multiple valid colorings, you can print any of them.

Input
The first line contains a single integer t
 (1≤t≤100) — the number of test cases.

The first line of each test case contains an integer n
 (3≤n≤50) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109). It is guaranteed a1≤a2≤…≤an−1≤an.

Output
For each test case, if it is impossible to color a to satisfy all the constraints, output NO.

Otherwise, first output YES
.*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        unordered_set<int> u(a.begin(), a.end());

        if (u.size() <= 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            string c(n, 'R');
            c[1] = 'B';
            cout << c << endl;
        }
    }
    return 0;
}