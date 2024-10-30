
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
        vi arr(n);
        take(arr);
        int andVal = arr[0];
        for(int i=1;i<n;i++){
            andVal&=arr[i];
        }
        
        int multiplier = 1;
        int ans=0;
        while(andVal>= multiplier){
            if(andVal&multiplier){
                ans+=multiplier;
            }
            multiplier*=2;
        }
        cout<<ans<<endl;
       
       
    }
    return 0;
}