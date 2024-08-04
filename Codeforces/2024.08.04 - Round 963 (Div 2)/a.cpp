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
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < 4 * n; i++)
        {
            if (s[i] == 'A')
            {
                a++;
            }
            if (s[i] == 'B')
            {
                b++;
            }
            if (s[i] == 'C')
            {
                c++;
            }
            if (s[i] == 'D')
            {
                d++;
            }
        }
        a = min(a, n);
        b = min(b, n);
        c = min(c, n);
        d = min(d, n);
        cout << a + b + c + d << endl;
    }
    return 0;
}