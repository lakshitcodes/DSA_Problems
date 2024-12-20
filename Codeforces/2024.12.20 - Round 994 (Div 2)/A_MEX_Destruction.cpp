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
        vi arr(n);
        take(arr);
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                if(start==-1){
                    start=i;
                }
                end=i;
            }
        }
        if(start==-1){
            cout<<0<<endl;
            continue;
        }
        bool valid=false;
        for(int i=start;i<=end;i++){
            if(arr[i]==0){
                valid=true;
                break;
            }
        }

        cout<<1+valid<<endl;
    }
    return 0;
}