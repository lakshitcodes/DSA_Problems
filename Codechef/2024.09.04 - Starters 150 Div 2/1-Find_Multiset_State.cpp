#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START150B/problems/ARRAYSTATE

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
        int n, k;
        cin >> n >> k;
        vi arr(n);
        take(arr);
        ll sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        for (int i = k; i < n - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << sum + arr[n - 1] << endl;
    }
    return 0;
}