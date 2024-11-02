#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
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
        int n,k;
        cin>>n>>k;
        map<int,ll> mp;
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            mp[x]+=y;
        }
        priority_queue<ll> pq;
        for(auto i : mp){
            pq.push(i.second);
        }
        ll ans=0;
        while(!pq.empty() && n--){
            ans+=pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}