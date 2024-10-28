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
        if(n==6){
            cout<<"7\n1 2 4 6 5 3\n";
            continue;
        }
        if(n==5){
            cout<<"5\n2 1 3 4 5\n";
            continue;
        }
        if(n==7){
            cout<<"7\n2 4 5 1 3 6 7\n";
            continue;
        }
        bool isOdd = n%2==1;
        if(isOdd){
            n--;
        }
        vi ans;
        set<int> s;
        int val = log2(n);
        s.insert(pow(2,val));
        s.insert(pow(2,val)-1);
        s.insert(pow(2,val)-2);
        s.insert(1);
        s.insert(3);
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                ans.pb(i);
            }
        }
        ans.pb(1);
        ans.pb(3);
        ans.pb(pow(2,val)-2);
        ans.pb(pow(2,val)-1);
        ans.pb(pow(2,val));

        if(isOdd){
            ans.pb(n+1);
            cout<<n+1<<endl;
            for(auto i : ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<pow(2,val+1)-1<<endl;
            for(auto i : ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}