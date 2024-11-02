#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

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
        string s;
        cin >> s;
        int n;
        cin>>n;
        set<int> indexes;
        for(int i=0;i<s.length()-3;i++){
            if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
                indexes.insert(i);
            }
        }
        for(int i=0;i<n;i++){
            int ind;
            char c;
            cin>>ind>>c;
            if(s[ind-1]==c){
                if(indexes.size()){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                int start = max(0,ind-4);
                int end = min((int)s.length()-4,ind-1);
                s[ind-1]=c;
                for(int j=start;j<=end;j++){
                    if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='0' && s[j+3]=='0'){
                        indexes.insert(j);
                    }
                    else{
                        if(indexes.find(j)!=indexes.end())
                            indexes.erase(j);
                    }
                }
                if(indexes.size()){
                    cout<<"YES"<<endl;
                }
                else
                    cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}