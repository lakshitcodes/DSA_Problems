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
        string s;
        cin >> s;
        int n=s.length();
        cout<<1<<" "<<n<<" ";
        int first=-1;
        int begin=0;
        while(s[begin]=='0'){
            begin++;
        }
        s=s.substr(begin);
        n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                first=i;
                break;
            }
        }
        if(first==-1){
            cout<<n-1<<" "<<n-1<<endl;
            continue;
        }
        string required="";
        for(int i=first;i<n;i++){
            if(s[i]=='0'){
                required+='1';
            }else{
                required+='0';
            }
        }
        int l=0;
        int maxMatch=0;
        for(int i=0;i<first;i++){
            for(int j=0;j<=n-first;j++){
                if(s[i+j]!=required[j]){
                    if(j+1>maxMatch){
                        maxMatch=j+1;
                        l=i;
                    }
                    break;
                }
            }
        }
        cout<<l+1+begin<<" "<<l+n-first+begin<<endl;
    }
    return 0;
}