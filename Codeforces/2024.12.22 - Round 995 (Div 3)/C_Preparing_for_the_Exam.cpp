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
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define take(arr) for(auto &i : arr) cin>>i;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        vi ques(m);
        take(ques);
        set<int> ans;
        for(int i=1;i<=n;i++){
            ans.insert(i);
        }
        for(int i=0;i<k;i++){
            int x;
            cin >> x;
            if(ans.count(x))
                ans.erase(x);
        }
        string temp="";
        for(auto &i : ques){
            if(ans.count(i) && ans.size()==1){
                temp+='1';
            }
            else if(ans.size()==0){
                temp+='1';
            }
            else{
                temp+='0';
            }
        }
        cout << temp << endl;


    }
    return 0;
}