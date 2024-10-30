
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
        
        int a=0,b=0;
        int firsta=-1,lasta=-1,firstb=-1,lastb=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
                lasta=i;
                if(firsta==-1){
                    firsta=i;
                }
            }
            else{
                b++;
                lastb=i;
                if(firstb==-1){
                    firstb=i;
                }
            }
        }
        int ans = max({a,b,lasta-firsta+1,lastb-firstb+1});
        cout<<ans<<endl;
    }
    return 0;
}