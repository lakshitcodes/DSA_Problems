#include <bits/stdc++.h>
using namespace std;

/*
 
    उद्धरेदात्मनात्मनं नात्मानमवसादयेत्।
    आत्मैव ह्यात्मनो बन्धुरात्मैव रिपुरात्मनः॥
    (Bhagavad Gita, Chapter 6, Verse 5)
 
    Transliteration:
    uddhared-ātman-ātmanam nātmanam-avasādayet
    ātmaiva hy-ātmano bandhur-ātmaiva ripur-ātmanah
 
    Translation:
    "One should elevate oneself by one's own efforts and not degrade oneself.
    For, the self is the friend of the self, and the self is the enemy of the self."
 
    Meaning:
    This verse emphasizes that the power to achieve lies within you.
    Your mind and actions can either be your greatest allies or your worst enemies.
    By focusing on self-improvement and aligning your thoughts and efforts with your goals,
    you can elevate yourself to success. It encourages you to take responsibility for your actions
    and to have confidence in your ability to overcome obstacles.

    Author: Lakshit Jain
*/

// Question Link : https://www.codechef.com/START181B/problems/GOODMATRIX

#define ll long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define m(a,b) map<a,b>
#define um(a,b) unordered_map<a,b>
#define f(i,a,b) for(int i=a;i<b;i++)
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define maxel(arr) *max_element(arr.begin(),arr.end())
#define minel(arr) *min_element(arr.begin(),arr.end())
#define rsort(arr) sort(arr.rbegin(),arr.rend())
#define take(arr) for(auto &i : arr) cin>>i;
#define show(arr) for(auto i : arr) cout<<i<<' ';
#define endl "\n"
#define int long long
#define MOD 1000000007

ll modPow(ll x,ll y,ll mod=MOD){ll res=1;x=(x)%mod;while (y>0){if (y&1) res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll ask(ll a,ll b){
    cout<<"? "<<a<<' '<<b<<endl;
    cout.flush();
    ll x;
    cin>>x;
    return x;
}
int find(vector<vi> &arr,int d1,int d2){
    map<int,int> mp;
    int n=arr.size();
    int m=arr[0].size();
    f(i,0,n){
        f(j,0,m){
            mp[arr[i][j]-i*d1-j*d2]++;
        }
    }
    
    int maxFreq=0;
    set<int> maxElements;
    for(auto &i : mp){
        if(i.second>maxFreq){
            maxElements.clear();
            maxFreq=i.second;
            maxElements.insert(i.first);
        }
        else if(i.second==maxFreq){
            maxElements.insert(i.first);
        }
    }
    int ans=INT_MAX;
    for(auto &ele : maxElements){
        int curr=0;
        f(i,0,n){
            f(j,0,m){   
                if(arr[i][j]!=ele+d1*i+d2*j){
                    curr++;
                }
            }
        }
        ans=min(ans,curr);
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vi> arr(n,vi(m));
    f(i,0,n){
        take(arr[i]);
    }
    
    int ops=find(arr,1,1);
    ops=min(ops,find(arr,1,-1));
    ops=min(ops,find(arr,-1,1));
    ops=min(ops,find(arr,-1,-1));
    cout<<ops<<endl;
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}