
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
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x%2){
                odd++;
            }
            else{
                even++;
            }
        }
        if(odd==0){
            cout<<0<<endl;
            continue;
        }
        odd--;
        cout<<1+(even) + (odd/2)<<endl;
    }
    return 0;
}