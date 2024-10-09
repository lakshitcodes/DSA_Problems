
#include <bits/stdc++.h>
using namespace std;

//Question Link : 

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
        int n;
        cin>>n;
        if(n<4){
            cout<<0<<endl;
            continue;
        }
        n/=2;
        int a=n/2;
        int b=n-a;
        cout<<a*b<<endl;
    }
    return 0;
}