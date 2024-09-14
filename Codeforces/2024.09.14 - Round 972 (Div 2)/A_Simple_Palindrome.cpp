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
#define m(a, b) map<a, b>
#define set(a, b) set<a, b>
#define sort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
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
        string temp = "aeiou";
        string s = "";
        if (n <= 5)
        {
            cout << temp.substr(0, n);
            cout << endl;
            continue;
        }
        for (int i = 0; i < 5; i++)
        {
            s += string((n - 5) / 5, temp[i]) + temp[i];
            if ((n - 5) % 5 - 1 >= i)
            {
                s += temp[i];
            }
        }
        cout << s << endl;
    }
    return 0;
}