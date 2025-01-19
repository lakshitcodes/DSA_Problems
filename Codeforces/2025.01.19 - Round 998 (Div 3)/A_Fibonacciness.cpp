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
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        int x = a+b;
        int y = d-c;

        int ansA=0;
        if(a+b==x){
            ansA++;
        }
        if(b+x==c){
            ansA++;
        }
        if(x+c==d){
            ansA++;
        }

        int ansB=0;
        if(a+b==y){
            ansB++;
        }
        if(b+y==c){
            ansB++;
        }
        if(y+c==d){
            ansB++;
        }

        cout<<max(ansA,ansB)<<endl;
    }
    return 0;
}