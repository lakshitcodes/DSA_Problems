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

int bs1(int i,vll&a,ll x,ll sum){
    int low=i+1;
    int high=a.size()-1;
    int ind=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(sum-a[mid]>=x){
            ind=mid;
            low=mid+1;
           
        }
        else{
            high=mid-1;
        }
    }
    return ind;
}
int bs2(int i,vll&a,ll y,ll sum){
    int low=i+1;
    int high=a.size()-1;
    int ind=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(sum-a[mid]<=y){
            ind=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ind;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=0;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        vll a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        ll cnt=0;
        for(int i=0;i<n-1;i++){
            sum-=a[i];
            int hi=bs1(i,a,x,sum);
            int si=bs2(i,a,y,sum);
            if(si==-1||hi==-1)cnt+=0;
            else cnt+=(hi-si+1);
            sum+=a[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}