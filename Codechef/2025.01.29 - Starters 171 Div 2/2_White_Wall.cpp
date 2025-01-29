#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.codechef.com/START171B/problems/WHITEWALL

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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count1=0;
        for(int i=0;i<s.length();i+=3){
            if(s[i]!='R'){
                count1++;
            }
        }
        for(int i=1;i<s.length();i+=3){
            if(s[i]!='G'){
                count1++;
            }
        }
        for(int i=2;i<s.length();i+=3){
            if(s[i]!='B'){
                count1++;
            }
        }
        int ans=count1;
        count1=0;
        for(int i=0;i<s.length();i+=3){
            if(s[i]!='R'){
                count1++;
            }
        }
        for(int i=1;i<s.length();i+=3){
            if(s[i]!='B'){
                count1++;
            }
        }
        for(int i=2;i<s.length();i+=3){
            if(s[i]!='G'){
                count1++;
            }
        }
        ans=min(ans,count1);
        count1=0;
        for(int i=0;i<s.length();i+=3){
            if(s[i]!='G'){
                count1++;
            }
        }
        for(int i=1;i<s.length();i+=3){
            if(s[i]!='B'){
                count1++;
            }
        }
        for(int i=2;i<s.length();i+=3){
            if(s[i]!='R'){
                count1++;
            }
        }
        ans=min(count1,ans);
        count1=0;
        for(int i=0;i<s.length();i+=3){
            if(s[i]!='G'){
                count1++;
            }
        }
        for(int i=1;i<s.length();i+=3){
            if(s[i]!='R'){
                count1++;
            }
        }
        for(int i=2;i<s.length();i+=3){
            if(s[i]!='B'){
                count1++;
            }
        }
        ans=min(ans,count1);
        count1=0;
        for(int i=0;i<s.length();i+=3){
            if(s[i]!='B'){
                count1++;
            }
        }
        for(int i=1;i<s.length();i+=3){
            if(s[i]!='G'){
                count1++;
            }
        }
        for(int i=2;i<s.length();i+=3){
            if(s[i]!='R'){
                count1++;
            }
        }
        ans=min(ans,count1);
        count1=0;for(int i=0;i<s.length();i+=3){
            if(s[i]!='B'){
                count1++;
            }
        }
        for(int i=1;i<s.length();i+=3){
            if(s[i]!='R'){
                count1++;
            }
        }
        for(int i=2;i<s.length();i+=3){
            if(s[i]!='G'){
                count1++;
            }
        }
        cout<<min(ans,count1)<<endl;
    }
    return 0;
}