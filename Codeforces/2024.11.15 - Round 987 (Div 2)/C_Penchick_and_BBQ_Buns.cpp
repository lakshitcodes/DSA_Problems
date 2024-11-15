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
        if(n%2 && n<27){
            cout<<-1<<endl;
            continue;
        }
        if(n%2==0){
            int i=1;
            for(int j=0;j<n/2;j++){
                cout<<i<<" "<<i<<" ";
                i++;
            }
        }
        else{
            string s = "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12";
            cout<<s<<" ";
            n-=27;
            int counter = 14;
            for(int i=0;i<n/2;i++){
                cout<<counter<<" "<<counter<<" ";
                counter++;
            }
        }
        cout<<endl;

    }
    return 0;
}