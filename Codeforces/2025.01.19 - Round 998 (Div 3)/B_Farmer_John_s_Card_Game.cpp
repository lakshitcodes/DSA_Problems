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
// #define sort(arr) sort(arr.begin(),arr.end())
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
        bool possible=true;
        vector<pair<int,vector<int>>> arr;
        for(int i=0;i<n;i++){
            vi temp(m);
            take(temp);
            sort(temp.begin(),temp.end());
            for(int i=1;i<m;i++){
                if(temp[i]-temp[i-1]!=n){
                    possible=false;
                    break;
                }
            }
            arr.pb({i,temp});
        }
        if(!possible){
            cout << "-1\n";
            continue;
        }   

        sort(arr.begin(),arr.end(),[](pair<int,vector<int>> a,pair<int,vector<int>> b){
            return a.second[0]<b.second[0];
        });
        for(int i=0;i<n;i++){
            cout<<arr[i].first+1<<" ";
        }
        cout<<"\n";

    }
    return 0;
}   