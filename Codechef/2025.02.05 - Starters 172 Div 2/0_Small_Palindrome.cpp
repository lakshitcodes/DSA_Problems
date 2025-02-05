
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
        int a,b;
        cin>>a>>b;
        for(int i=1;i<=a/2;i++){
            cout<<1;
        }
        for(int i=1;i<=b;i++){
            cout<<2;
        }
        for(int i=1;i<=a/2;i++){
            cout<<1;
        }
        cout<<endl;
    }
    return 0;
}