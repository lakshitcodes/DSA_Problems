
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
#define take(arr) for(auto &i : arr) cin>>i;
#define int long long

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        cin>>a>>b;
        vi idx(b.length(),-1);
        int i=a.length()-1;
        int j=b.length()-1;
        
        while(i>=0 && j>=0){
            if(a[i]==b[j]){
                idx[j]=i;
                i--;j--;
            }
            else{
                i--;
            }
        }
        if(j>=0 && i<0){
            cout<<-1<<endl;
            continue;
        }
        int ans=0;
        int removed=0;
        
        int prev=0;
        for(auto &i : idx){
            for(int j=prev;j<i;j++){
                ans+=j-removed+1;
                // cout<<ans<<" ";
                removed++;
            }
            prev=i+1;
        }
        for(int i=prev;i<a.length();i++){
            ans+=i-removed+1;
            removed++;
        }
        cout<<ans<<endl;
    }
    return 0;
}