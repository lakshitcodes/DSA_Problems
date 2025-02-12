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

ll interact(ll a,ll b){
    cout<<"? "<<a<<' '<<b<<endl;
    cout.flush();
    ll x;
    cin>>x;
    return x;
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        take(arr);
        vi present(n+1,0);
        vi idx(n+1,0);
        for(int i=0;i<n;i++){
            present[arr[i]]=1;
            idx[arr[i]]=i+1;
        }
        bool found=false;
        for(ll i=1;i<=n;i++){
            if(present[i]==0){
                ll dis=interact(i,i%n +1);
                if(dis==0){
                    cout<<"! A"<<endl;
                    cout.flush();
                }else{
                    cout<<"! B"<<endl;
                    cout.flush();
                }
                found=true;
                break;
            }
        }
        if(found)   continue;
        ll dis1 = interact(idx[1],idx[n]);
        ll dis2 = interact(idx[n],idx[1]);

        if(dis1>=n){
            cout<<"! B"<<endl;
            cout.flush();
        }else if(dis1<n-1){
            cout<<"! A"<<endl;
            cout.flush();
        }else if(dis2==dis1){
            cout<<"! B"<<endl;
            cout.flush();
        }
        else{
            cout<<"! A"<<endl;
            cout.flush();
        }

    }
    return 0;
}