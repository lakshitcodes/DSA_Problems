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
        int m,n;
        cin>>m>>n;
        vector<string> arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }

        vector<string> layers;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom && left<=right){
            string curr="";
            for(int i=left;i<=right;i++){

                curr+=arr[top][i];
            }
            top++;
            for(int i=top;i<=bottom;i++){
                curr+=arr[i][right];
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    curr+=arr[bottom][i];
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                curr+=(arr[i][left]);
                }
                left++;
            }
            layers.pb(curr);
        }
        int count=0;
        for(int i=0;i<layers.size();i++){
            int p=layers[i].length();
            for(int j=0;j<p;j++){
                if(layers[i][j]=='1' && layers[i][(j+1)%p]=='5' && layers[i][(j+2)%p]=='4' && layers[i][(j+3)%p]=='3'){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}