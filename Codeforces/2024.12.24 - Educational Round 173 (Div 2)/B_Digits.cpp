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
        int n,d;
        cin >> n >> d;
        cout<<1<<" ";
        if(d%3==0 || n>=3){
            cout<<3<<" ";
        }
        if(d==5){
            cout<<5<<" ";
        }
        if(d==7 || n>=3){
            cout<<7<<" ";
        }
        if(d==9 || n>=6 || (d%3==0 && n>=3)){
            cout<<9<<" ";
        }
        cout<<endl;
    }
    return 0;
}   