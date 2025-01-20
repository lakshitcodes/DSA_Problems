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

int findLargestSmallerThanX(const vector<int>& arr, int x, int low) {
    int high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x) {
            result = arr[mid];  
            low = mid + 1;
        } else {
            high = mid - 1;  
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        map<int,int> st;
        int ans = -1;
        vi pairs;
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            st[arr[i]]++;
            if(st[arr[i]] >= 4) {
                ans = arr[i];
            }
        }

        if(ans != -1) {
            cout << ans << " " << ans << " " << ans << " " << ans << endl;
            continue;
        }

        map<int,int> temp_st = st;  
        for(auto i : temp_st) {
            if(i.second >= 2) {
                pairs.pb(i.first);
                i.second-=2;
                if(i.second==0){
                    int ele=i.first;
                    st.erase(ele);
                }
            }
        }

        if(pairs.size() >= 2) {
            cout << pairs[pairs.size()-1] << " " << pairs[pairs.size()-1] << " " 
                 << pairs[pairs.size()-2] << " " << pairs[pairs.size()-2] << endl;
            continue;
        }

        if(pairs.size() == 1) {
            vi temp;
            for(auto &i : st) {
                temp.pb(i.first);
            }
            sort(temp);
            
            bool found = false;
            for(int i = 0; i < temp.size(); i++) {
                int x = temp[i];
                int target = 2 * pairs[0] + x;  
                int y = findLargestSmallerThanX(temp, target, i+1);
                if(y != -1) {
                    cout << pairs[0] << " " << pairs[0] << " " << x << " " << y << endl;
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "-1" << endl;
            }
        } else {
            cout << "-1" << endl;  
        }
    }
    return 0;
}