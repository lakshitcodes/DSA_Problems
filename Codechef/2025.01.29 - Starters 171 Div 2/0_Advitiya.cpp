#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START171B/problems/ADVITIYA

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
        string s;
        cin>>s;
        string curr = "ADVITIYA";
        int ans=0;
        for(int i=0;i<8;i++){
            if(s[i]!=curr[i]){
                if(s[i]<curr[i])
                    ans+=abs(s[i] - curr[i]);
                else{
                    ans+= 26 - abs(s[i] - curr[i]);
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}