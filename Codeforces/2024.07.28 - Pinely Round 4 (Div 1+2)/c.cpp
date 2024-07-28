#include <bits/stdc++.h>
using namespace std;

/*
C. Absolute Zero
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array a of n integers.

In one operation, you will perform the following two-step move:

Choose an integer x (0≤x≤109).
Replace each ai with |ai−x|, where |v| denotes the absolute value of v.
For example, by choosing x=8, the array [5,7,10] will be changed into [|5−8|,|7−8|,|10−8|]=[3,1,2].

Construct a sequence of operations to make all elements of a equal to 0 in at most 40 operations or determine that it is impossible. You do not need to minimize the number of operations.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109) — the elements of the array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer −1 if it is impossible to make all array elements equal to 0 in at most 40 operations.

Otherwise, output two lines. The first line of output should contain a single integer k (0≤k≤40) — the number of operations. The second line of output should contain k
 integers x1,x2,…,xk (0≤xi≤109) — the sequence of operations, denoting that on the i-th operation, you chose x=xi.

If there are multiple solutions, output any of them.

You do not need to minimize the number of operations.
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
        vi storeK;
        if (n == 1)
        {
            cout << 1 << endl
                 << arr[0] << endl;
            continue;
        }
        for (int i = 0; i < 40; i++)
        {
            sort(arr.begin(), arr.end());
            int diff = arr[n - 1] == arr[n - 2] ? (arr[n - 1] + arr[0]) / 2 : (arr[n - 1] + arr[n - 2]) / 2;
            if (diff == 0)
            {
                break;
            }
            storeK.pb(diff);
            for (auto &i : arr)
            {
                i = abs(i - diff);
            }
        }
        if (arr[0] == 0 && arr.back() == 0)
        {
            cout << storeK.size() << endl;
            for (auto &k : storeK)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl
                 << endl;
        }
    }
    return 0;
}