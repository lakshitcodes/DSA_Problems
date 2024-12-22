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
        ll n,a,b,c;
        cin >> n>>a>>b>>c;
        long long totalCycleDistance = a + b + c; 
        long long cycles = n / totalCycleDistance; 
        long long distanceCovered = cycles * totalCycleDistance; 
        int days = cycles * 3;

        if (distanceCovered < n) {
            distanceCovered += a; 
            days++;
            if (distanceCovered >= n) goto abc;
            
            distanceCovered += b;
            days++;
            if (distanceCovered >= n) goto abc;
            
            distanceCovered += c;
            days++;
        }
        abc:
        cout<<days<<endl;
    }
    return 0;
}