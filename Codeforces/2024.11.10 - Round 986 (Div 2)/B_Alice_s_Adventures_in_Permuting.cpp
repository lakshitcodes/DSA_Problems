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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, b, c;
        cin >> n >> b >> c;
        
        if (b == 0) {
            if (c >= n) {
                cout << n << "\n";
            }
            else if(c==n-1){
                cout<<c<<endl;
            }
            else if(c==n-2){
                cout<<c+1<<endl;
            }
            else{
                cout<<-1<<endl;
            }
            continue;
        }
        
        if(c>=n){
            cout<<n<<endl;
            continue;
        }
        cout<< n- ((n-1-c)/b+1)<<endl;
    }
    return 0;
}