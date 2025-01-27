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
        bool poss=true;
        for(int i=0;i<n;i++){
            int left = i;
            int right = n-i-1;
            int maxi = max(2*right,2*left);
            if(arr[i]<=maxi){
                poss=false;
                break;
            }
        }
        if(poss){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}