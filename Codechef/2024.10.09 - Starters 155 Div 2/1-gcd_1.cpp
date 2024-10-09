
#include <bits/stdc++.h>
using namespace std;

//Question Link: https://www.codechef.com/START155B/problems/GCD_1

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
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                cout<<k+j<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}