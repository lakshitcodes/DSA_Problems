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
        cin >> n;
        if(n<5){
            cout<<-1<<endl;
        }
        else if(n==5){
            cout<<"1 3 5 4 2"<<endl;
        }
        else if(n==6){
            cout<<"1 3 5 4 2 6"<<endl;
        }
        else if(n==7){
            cout<<"1 3 7 5 4 6 2"<<endl;
        }
        else{
            for(int i=2;i<=n;i+=2){
                if(i==8){
                    continue;
                }
                cout<<i<<" ";
            }
            cout<<8<<" "<<1<<" "<<3<<" ";
            for(int i=5;i<=n;i+=2){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}