#include <bits/stdc++.h>
using namespace std;

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

// //This codes gives TLE
// bool isPrime(int n)
// {
//     if (n <= 1)
//     {
//         return false;
//     }
//     if (n <= 3)
//     {
//         return true;
//     }
//     if (n % 2 == 0 || n % 3 == 0)
//     {
//         return false;
//     }
//     for (int i = 5; i * i <= n; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         unordered_map<int, vi> adj;
//         vector<int> count(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = i + 1; j <= n; j++)
//             {
//                 if (isPrime(i ^ j))
//                 {
//                     adj[i].pb(j);
//                     count[j]++;
//                 }
//             }
//         }
//         queue<int> q;
//         vector<int> colors(n + 1, 1);
//         for (int i = 1; i <= n; i++)
//         {
//             if (count[i] == 0)
//             {
//                 q.push(i);
//             }
//         }
//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();
//             for (auto &x : adj[u])
//             {
//                 count[x]--;
//                 if (count[x] == 0)
//                 {
//                     q.push(x);
//                 }
//                 if (colors[x] <= colors[u])
//                 {
//                     colors[x] = 1 + colors[u];
//                 }
//             }
//
//         cout << *max_element(colors.begin() + 1, colors.end()) << endl;
//         for (int i = 1; i <= n; ++i)
//         {
//             cout << colors[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

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
        if (n == 1)
        {
            cout << 1 << endl
                 << 1 << endl;
        }
        else if (n == 2)
        {
            cout << 2 << endl
                 << 1 << " " << 2 << endl;
        }
        else if (n == 3)
        {
            cout << 2 << endl
                 << 1 << " " << 2 << " " << 2 << endl;
        }
        else if (n < 6)
        {
            cout << 3 << endl;
            cout << "1 2 2 3 ";
            if (n == 5)
            {
                cout << 3 << endl;
            }
        }
        else
        {
            cout << 4 << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << (i - 1) % 4 + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}