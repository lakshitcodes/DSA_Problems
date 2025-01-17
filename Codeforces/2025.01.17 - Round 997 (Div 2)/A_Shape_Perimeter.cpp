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
        int n,m;
        cin >> n >> m;

        int ans=0;
        bool first=false;
        while(n--){
            int x,y;
            cin>>x>>y;
            if(first)
                ans+=4*m - 2*(m-x) - 2*(m-y);
            else    ans+=4*m;
            first=true;
        }
        cout<<ans<<endl;
    }
    return 0;
}   