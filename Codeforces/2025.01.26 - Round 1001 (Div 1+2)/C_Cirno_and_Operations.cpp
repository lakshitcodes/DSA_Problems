#define ll long long
#define vi vector<int>
#define fi for(int i=0;i<n;i++)
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=0;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if (n == 1) {
            cout << a[0] << endl;
            continue;
        }
        ll maxi = 0;
        for (auto &num:a) {
            maxi += num;
        }
        for (int k = 1; k <= n-1; k++) {
            vector<ll> current = a;
            for (int step = 0; step < k; step++) {
                if (current.size() == 1) break;
                if (current[0] > current.back()) {
                    reverse(current.begin(), current.end());
                }
                vector<ll> diff;
                for (int i = 0; i<current.size()-1;i++) {
                    diff.push_back(current[i+1]-current[i]);
                }
                current = diff;
            }
            ll sum = 0;
            for (auto&num:current) {
                sum += num;
            }
            if (sum > maxi) maxi = sum;
        }
        cout <<maxi<< endl;
        
    }
    return 0;
}
