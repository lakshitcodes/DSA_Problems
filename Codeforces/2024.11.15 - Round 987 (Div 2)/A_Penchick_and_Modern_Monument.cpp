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

int helper(vector<int>& nums) {
    vector<int> dp; 

    for (int num : nums) {
        auto it = upper_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num); 
        } else {
            *it = num;
        }
    }
    return dp.size(); 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi arr(n);
        take(arr);
       cout<<n-helper(arr)<<endl;
    }
    return 0;
}