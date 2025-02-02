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
        int n,k;
        cin>>n>>k;
        vi arr(n);
        take(arr);
        if(n==k){
            int ans=-1;
            int counter=1;
            for(int i=1;i<n;i+=2){
                if(arr[i]!=counter){
                    ans=counter;
                    break;
                }
                counter++;
            }
            if(ans==-1){
                cout<<k/2+1<<endl;
            }else{
                cout<<ans<<endl;
            }
            continue;
        }
        bool found=false;
        for(int i=1;i<=n-k+1;i++){
            if(arr[i]!=1){
                found=true;
                break;
            }
        }
        if(found){
            cout<<1<<endl;
            continue;
        }
        bool check2=false;
        for(int i=2;i<=n-k+2;i++){
            if(arr[i]!=2){
                check2=true;
                break;
            }
        }
        if(check2){
            cout<<2<<endl;
            continue;
        }
        cout<<3<<endl;
    }
    return 0;
}