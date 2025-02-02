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
        vector<vi> arr(n,vi(n));
        vi count;
        for(int i=0;i<n;i++){
            take(arr[i]);
            int count1=0;
            for(int j=n-1;j>=0;j--){
                if(arr[i][j]==1){
                    count1++;
                }
                else{
                    break;
                }
            }
            if(count1>0){
                count.pb(count1);
            }
        }
        sort(count);
        int expected=1;
        // for(auto &i : count){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<count.size();i++){
            if(count[i]>=expected){
                expected++;
            }
        }
        cout<<min(expected,n)<<endl;
    }
    return 0;
}