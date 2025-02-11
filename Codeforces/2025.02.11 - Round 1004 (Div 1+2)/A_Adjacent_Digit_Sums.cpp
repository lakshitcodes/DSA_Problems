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
#define um(a,b) unordered_map<a,b>
#define f(i,a,b) for(int i=a;i<b;i++)
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define max(arr) *max_element(arr.begin(),arr.end())
#define min(arr) *min_element(arr.begin(),arr.end())
#define rsort(arr) sort(arr.rbegin(),arr.rend())
#define take(arr) for(auto &i : arr) cin>>i;
#define show(arr) for(auto i : arr) cout<<i<<' ';
#define endl "\n"
#define int long long

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int x,y;
        cin>>x>>y;
        
        if((x+1-y)>=0 && (x+1-y)%9==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}