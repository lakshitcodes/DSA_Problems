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
#define m(a, b) map<a, b>
#define um(a, b) unordered_map<a, b>
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define fsort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define maxel(arr) *max_element(arr.begin(), arr.end())
#define minel(arr) *min_element(arr.begin(), arr.end())
#define rsort(arr) sort(arr.rbegin(), arr.rend())
#define take(arr)       \
    for (auto &i : arr) \
        cin >> i;
#define endl "\n"
#define int long long
#define MOD 1000000007

ll modPow(ll x, ll y, ll mod = MOD)
{
    ll res = 1;
    x = (x) % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
void show(vll &arr)
{
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;
}

vector<bool> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    ll x;
    cin >> x;
    return x;
}

void lakshitcodes()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi arr(n);
    take(arr);
    vi left(n, 0);
    vi right(n, 0);
    int maxi = INT_MIN;
    int curr = 0;
    rf(i, n - 1, 0)
    {
        if (s[i] == '1')
        {
            curr += arr[i];
            right[i] = curr;
            maxi = max(maxi, curr);
            if (curr < 0)
            {
                curr = 0;
            }
        }
        else
        {
            curr = 0;
        }
    }
    curr = 0;
    bool zero = false;
    f(i, 0, n)
    {
        if (s[i] == '1')
        {
            curr += arr[i];
            left[i] = curr;
            maxi = max(maxi, curr);
            if (curr < 0)
            {
                curr = 0;
            }
        }
        else
        {
            zero = true;
            curr = 0;
        }
    }
    if (maxi > k || (maxi != k && !zero))
    {
        cout << "No\n";
        return;
    }
    f(i, 0, n)
    {
        if (s[i] == '0')
        {
            int val = k;
            if (i - 1 >= 0 && left[i - 1] > 0)
            {
                val -= left[i - 1];
            }
            if (i + 1 < n && right[i + 1] > 0)
            {
                val -= right[i + 1];
            }
            arr[i] = val;
            s[i] = '1';
            break;
        }
    }
    cout << "Yes\n";
    f(i, 0, n)
    {
        if (s[i] == '0')
        {
            cout << -9999999999999 << " ";
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lakshitcodes();
    }
    return 0;
}