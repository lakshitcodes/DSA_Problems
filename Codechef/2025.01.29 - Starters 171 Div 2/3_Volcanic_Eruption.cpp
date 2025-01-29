#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START171B/problems/VOLCANO

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define m(a,b) map<a,b>
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define take(arr) for(auto &i : arr) cin>>i;
#define int ll


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,p;
        cin>>n>>p;
        vi arr(n);
        vi vol;
        vi ans(n,INT_MAX);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                vol.pb(i);
                ans[i]=0;
            }
        }

        int idx = 0;
        for (int i = 0; i < vol.size(); i++) {
            int currMaxi = 0;
            for (int j = vol[i] - 1; j >= idx; j--) {
                currMaxi = max(arr[j], currMaxi);
                ans[j] = min(ans[j], (currMaxi + p - 1) / p);
            }
            idx = vol[i] + 1;
        }
        idx = n - 1;
        for (int i = vol.size() - 1; i >= 0; i--) {
            int currMaxi = 0;
            for (int j = vol[i] + 1; j <= idx; j++) {
                currMaxi = max(arr[j], currMaxi);
                ans[j] = min(ans[j], (currMaxi + p - 1) / p);
            }
            idx = vol[i] - 1;
        }

        for(auto &i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}