#include <bits/stdc++.h>
using namespace std;

/*
C. Good Prefixes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alex thinks some array is good if there exists some element that can be represented as the sum of all other elements (the sum of all other elements is 0
 if there are no other elements). For example, the array [1,6,3,2] is good since 1+3+2=6. Furthermore, the array [0]
 is also good. However, the arrays [1,2,3,4] and [1] are not good.

Alex has an array a1,a2,…,an. Help him count the number of good non-empty prefixes of the array a. In other words, count the number of integers i
 (1≤i≤n) such that the length i prefix (i.e. a1,a2,…,ai) is good.

Input
The first line of the input contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of elements in the array.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109) — the elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer — the number of good non-empty prefixes of the array a
.*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int maxEle = nums[0];
        long long ans = 0;
        long long currSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];
            maxEle = max(maxEle, nums[i]);
            if (2 * maxEle == currSum)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}