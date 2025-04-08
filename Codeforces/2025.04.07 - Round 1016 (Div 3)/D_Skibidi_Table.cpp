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
#define fsort(arr) sort(arr.begin(),arr.end())
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

ll solveQuery1(ll x, ll y, ll n) {
    if (n == 1) {
        if (x == 1 && y == 1) return 1; 
        if (x == 2 && y == 2) return 2; 
        if (x == 2 && y == 1) return 3;
        if (x == 1 && y == 2) return 4; 
        return -1;
    }
    
    ll half = 1LL << (n-1); 
    ll limit = half * half;
    

    if (x <= half && y <= half) {
        return solveQuery1(x, y, n-1);
    } else if (x > half && y > half) {
        return limit + solveQuery1(x - half, y - half, n-1);
    } else if (x > half && y <= half) {
        return 2 * limit + solveQuery1(x - half, y, n-1);
    } else {
        return 3 * limit + solveQuery1(x, y - half, n-1);
    }
}

pair<ll, ll> getCoord(ll val, ll n) {
    if (n == 1) {
        if (val == 1) return {1, 1}; 
        if (val == 2) return {2, 2}; 
        if (val == 3) return {2, 1};
        if (val == 4) return {1, 2}; 
        return {-1, -1}; 
    }
    
    ll half = 1LL << (n-1); 
    ll limit = half * half;
    
    pair<ll, ll> coords;
    
    if (val <= limit) {
        return getCoord(val, n-1);
    } else if (val <= 2 * limit) {
        coords = getCoord(val - limit, n-1);
        return {coords.first + half, coords.second + half};
    } else if (val <= 3 * limit) {
        coords = getCoord(val - 2 * limit, n-1);
        return {coords.first + half, coords.second};
    } else {
        coords = getCoord(val - 3 * limit, n-1);
        return {coords.first, coords.second + half};
    }
}


string solveQuery2(ll val, ll n) {
    pair<ll, ll> coords = getCoord(val, n);
    return to_string(coords.first) + " " + to_string(coords.second);
}

void lakshitcodes() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    
    while (q--) {
        char a,b;
        cin >> a>>b;
        
        if (a == '-' && b == '>') {
            int x, y;
            cin >> x >> y;
            cout << solveQuery1(x, y, n) << endl;
        } else if (a == '<' && b == '-') {
            int val;
            cin >> val;
            cout << solveQuery2(val, n) << endl;
        }
    }
}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        lakshitcodes();
    }
    return 0;
}