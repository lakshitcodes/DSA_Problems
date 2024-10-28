#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define m(a,b) map<a,b>
#define set(a,b) set<a,b>
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define take(arr) for(auto &i : arr) cin>>i;

bool helper(vi& arr, ll k) {
    ll n = arr.size();
    ll temp = 0;
    for (ll i = 1; i < n; ++i) {
        if (arr[i] - arr[i - 1] <= k) {
            temp++;
            i++;  
        }
    }
    return temp >= (n / 2);
}

ll solve(vi& arr) {
    ll l = 0, r = arr.back() - arr[0];
    ll res = r;

    while (l <= r) {
        ll mid = (l + r) / 2;
        if (helper(arr, mid)) {
            res = mid; 
            r = mid - 1;
        } else {
            l = mid + 1;  
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi arr(n);
        take(arr);
        if(n<2){
            cout<<1<<endl;
            continue;
        }

        cout << solve(arr) << endl;
    }
    return 0;
}
