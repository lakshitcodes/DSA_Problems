
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
        int even=0,odd=0;
        for(int i=1;i<=sqrt(n)+1;i++){
            if(n%i==0){
                even+=(n/i)%2==0;
                odd+=(n/i)%2;
                even+=i%2==0;
                odd+=i%2;
            }
        }
        if(even>odd){
            cout<<1<<endl;
        }
        if(even==odd){
            cout<<0<<endl;
        }
        if(even<odd){
            cout<<-1<<endl;
        }
    }
    return 0;
}