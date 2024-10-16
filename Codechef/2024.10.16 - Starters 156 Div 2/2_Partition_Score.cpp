
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
#define take(arr) for(auto &i : arr) cin>>i;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vll arr(n);
        take(arr);
        
        sort(arr.begin(),arr.end());
        
        int startIndex=k-1;
        ll ans=0;
        ans+=arr[n-1];
        ans+= startIndex==0 ? arr[n-1] : arr[0];
        ans+=arr[startIndex];
        ans+=arr[n-2];
        
        ll ans2=0;
        ans2+=arr[n-1];
        ans2+=arr[n-2];
        ans2+=arr[n-k-1];
        ans2+=arr[0];
        cout<<max(ans,ans2)<<endl;
    }
    return 0;
}