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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int p=INT_MAX,ss=-1;
        int dc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='p'){
                if(p==INT_MAX){
                    p=i;
                }
            }
            if(s[i]=='s'){
                ss=i;
            }
            if(p!=INT_MAX)
                dc+=s[i]=='.';
        }

        if(p<ss || (p!=INT_MAX && ss!=-1 && dc)){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}