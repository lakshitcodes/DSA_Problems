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
        int n;
        cin>>n;
        vi arr(n);
        take(arr);
        vi cnt(n+1,0);
        for(auto &i : arr){
            cnt[i]++;
        }
        bool valid=true;
        for(int i=1;i<n;i++){
            if(cnt[i]==1){
                valid=false;
                break;
            }
            if(cnt[i]>2){
                int total=cnt[i]-2;
                cnt[i+1]+=total;
                cnt[i]=2;
            }
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]%2){
                valid=false;
                break;
            }
        }
        cout<<(valid?"Yes":"No")<<endl;
    }
    return 0;
}