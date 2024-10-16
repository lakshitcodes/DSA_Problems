
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
        vi a(n);
        take(a);
        int thresh = a[n-1]/2;
        int index=n-2;
        while(index>=0 && a[index]<=thresh){
            index--;
        }
        cout<<index+2<<endl;
    }
    return 0;
}