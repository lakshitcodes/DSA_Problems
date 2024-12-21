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
#define m(a,b) map<a,b>
#define set(a,b) set<a,b>
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define take(arr) for(auto &i : arr) cin>>i;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
 
        vector<vi> restrictions;
 
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'p')
            {
                int length = i + 1;
                restrictions.push_back({length, 1, length});
            }
            else if (s[i] == 's')
            {
                int length = n - i;
                restrictions.push_back({length, i + 1, n});
            }
        }
 
        if (restrictions.size())
            sort(restrictions);
 
        bool possible = true;
 
        if (restrictions.size())
            for (int i = 0; i < restrictions.size() - 1; i++)
            {
                vi restriction1 = restrictions[i], restriction2 = restrictions[i + 1];
                int l1 = restriction1[1], r1 = restriction1[2], l2 = restriction2[1], r2 = restriction2[2];
                if (l1 >= l2 && r1 <= r2)
                {
                    continue;
                }
                else
                {
                    possible = false;
                }
            }
 
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}