#include <bits/stdc++.h>
using namespace std;

// After squaring , value goes out of bounds

/*
C. Squaring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
ikrpprpp found an array a consisting of integers. He likes justice, so he wants to make a fair — that is, make it non-decreasing. To do that, he can perform an act of justice on an index 1≤i≤n
 of the array, which will replace ai with a2i (the element at position i with its square). For example, if a=[2,4,3,3,5,3] and ikrpprpp chooses to perform an act of justice on i=4, a becomes [2,4,3,9,5,3].

What is the minimum number of acts of justice needed to make the array non-decreasing?

Input
First line contains an integer t (1≤t≤1000) — the number of test cases. It is followed by the description of test cases.

For each test case, the first line contains an integer n — size of the array a. The second line contains n (1≤n≤2⋅105) integers a1,a2,…,an (1≤ai≤106).

The sum of n over all test cases does not exceed 2⋅105.

Output
For each testcase, print an integer — minimum number of acts of justice required to make the array a non-decreasing. If it is impossible to do that, print −1
.
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
    {                   \
        cin >> i;       \
    }
#define mod 1000000007
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
        vector<long long int> arr(n);
        take(arr);
        ll count = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                if (arr[i] == 1)
                {
                    cout << -1 << endl;
                }
                else
                {
                    while (arr[i] < arr[i - 1])
                    {
                        arr[i] *= arr[i];
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}