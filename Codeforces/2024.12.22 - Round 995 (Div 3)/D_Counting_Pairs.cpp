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
        int n,x,y;
        cin >> n >> x >> y;
        vi arr(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum+=arr[i];
        }

        sort(arr);
        ll ans=0;
        for(int i=0;i<n-1;i++){
            ll remSum = sum-arr[i];

            ll maxPoss = remSum-x;
            ll minPoss = remSum-y;

            auto low = lower_bound(arr.begin()+i+1,arr.end(),minPoss);
            auto high = upper_bound(arr.begin()+i+1,arr.end(),maxPoss);

            ll temp = high-low;
            ans+=max(temp,0LL);
        }
        cout << ans << endl;

    }
    return 0;
}   