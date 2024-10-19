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
    while (t--) {
        int n;
        cin>>n;
        vll arr(n);
        ll maxi = INT_MIN;
        ll mini = INT_MAX;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        ll ans = (n-1)*(maxi-mini);
        cout<<ans<<endl;
    }
    return 0;
}   