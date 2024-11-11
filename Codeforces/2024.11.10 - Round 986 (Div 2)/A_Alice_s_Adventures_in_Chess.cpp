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
        int n,a,b;
        cin >> n >> a >> b;
        string s;
        cin>>s;
        int x=0,y=0;
        int i=0;
        int count=0;
        while(count<1e4){
            if(x==a && y==b){
                break;
            }
            if(s[i]=='N'){
                y++;
            }
            else if(s[i]=='S'){
                y--;
            }
            else if(s[i]=='E'){
                x++;
            }
            else{
                x--;
            }
            i++;
            i%=n;
            count++;
        }
        if(x==a && y==b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}