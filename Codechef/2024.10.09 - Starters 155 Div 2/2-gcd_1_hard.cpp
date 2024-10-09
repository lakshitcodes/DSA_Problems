
#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.codechef.com/START155B/problems/MINGCD_1

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
        int m,n;
        cin>>m>>n;
        vector<vi> ans(m,vi(n,2));
        for(int i=0;i<min(m,n);i++){
            ans[i][i]=3;
        }
        if(m>n){
            for(int i=n;i<m;i++){
                ans[i][n-1]=3;
            }
        }
        else if(m<n){
            for(int i=m;i<n;i++){
                ans[m-1][i]=3;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}