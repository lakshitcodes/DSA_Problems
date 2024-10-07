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
    ll t;
    cin >> t;
    while (t--) {
        ll n,x;
        cin >> n >> x;
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            mp[a]++;
        }
        for(int i=0;i<=1e9;i++){
            if(mp[i]){
                mp[i]--;
                ll count=mp[i];
                mp.erase(i);
                mp[i+x]+=count;
            }
            else{
                cout<<i<<endl;
                break;
            }
        }

        
    }
    return 0;
}