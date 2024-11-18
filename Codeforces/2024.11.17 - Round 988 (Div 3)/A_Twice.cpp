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
        set<int> s;
        vi arr(n);
        int count =0 ;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(s.find(arr[i]) == s.end()){
                s.insert(arr[i]);
            }else{
                count++;
                s.erase(arr[i]);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}