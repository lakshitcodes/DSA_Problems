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

class DSU {
    private:
        vi parent, rank, size;
        int num_sets;
        
    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            size.resize(n, 1);
            num_sets = n;
            
            f(i,0,n) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void unite(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
            
            if (root_x == root_y) {
                return;
            }
            
            if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
                size[root_y] += size[root_x];
            } else if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
                size[root_x] += size[root_y];
            } else {
                parent[root_y] = root_x;
                rank[root_x]++;
                size[root_x] += size[root_y];
            }
            
            num_sets--;
        }
        
        bool same_set(int x, int y) {
            return find(x) == find(y);
        }
        
        int get_size(int x) {
            return size[find(x)];
        }
        
        int count() {
            return num_sets;
        }
    };

void solve(){
    int n;
    cin>>n;
    vi a(n);
    vi query(n);
    take(a);
    take(query);

    DSU dsu(n+1);

    vector<bool> vis(n, false);

    f(i,0,n){
        if(!vis[i]){
            vis[i]=true;
            int x=a[i];
            do{
                dsu.unite(i+1,x);
                vis[x-1]=true;
                x=a[x-1];
            }while(x!=a[i]);
        }
    }
    int prevAns=0;
    unordered_set<int> parent;
    for(auto &i : query){
        int p=dsu.find(i);
        if(parent.find(p)==parent.end()){
            parent.insert(p);
            prevAns+=dsu.get_size(p);
        }
        cout<<prevAns<<" ";
    }
    cout<<endl;
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