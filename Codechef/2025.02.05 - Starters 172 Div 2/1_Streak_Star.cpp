
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
#define take(arr) for(auto &i : arr) cin>>i;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vi nums(n);
        take(nums);
        int ans=0;
        for(int i=0;i<n;i++){
            int ele=nums[i];
            int len=1;
            bool used=false;
            for(int j=i+1;j<n;j++){
                if(nums[j]>=ele){
                    len++;
                    ele=nums[j];
                }
                else{
                    if(nums[j]*k>=ele && !used){
                        used=true;
                        len++;
                        ele=nums[j]*k;
                    }else{
                        break;
                    }
                }
            }
            ans=max(ans,len);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}