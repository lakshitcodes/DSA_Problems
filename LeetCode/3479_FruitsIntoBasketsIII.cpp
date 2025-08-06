#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/fruits-into-baskets-iii/

class Solution
{
public:
#define ll long long
    class SegmentTree
    {
    public:
        vector<ll> seg;

        SegmentTree(ll n)
        {
            seg.resize(4 * n + 1);
        }
        void build(ll ind, ll low, ll high, vector<ll> &arr)
        {
            if (low == high)
            {
                seg[ind] = arr[low];
                return;
            }
            ll mid = (low + high) / 2;
            build(2 * ind + 1, low, mid, arr);
            build(2 * ind + 2, mid + 1, high, arr);

            seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
        }

        ll query(ll ind, ll low, ll high, ll l, ll r)
        {
            if (r < low || high < l)
            {
                return 0;
            }

            if (low >= l && high <= r)
            {
                return seg[ind];
            }
            ll mid = (low + high) >> 1;
            ll left = query(2 * ind + 1, low, mid, l, r);
            ll right = query(2 * ind + 2, mid + 1, high, l, r);

            return max(left, right);
        }
        void update(ll ind, ll low, ll high, ll i, ll val)
        {
            if (low == high)
            {
                seg[ind] = val;
                return;
            }

            ll mid = (low + high) >> 1;
            if (i <= mid)
            {
                update(2 * ind + 1, low, mid, i, val);
            }
            else
            {
                update(2 * ind + 2, mid + 1, high, i, val);
            }
            seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
        }
    };

    ll res;
    void find(ll val, SegmentTree &st, ll n)
    {
        ll low = 0;
        ll high = n - 1;

        ll ans = -1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            ll mx = st.query(0, 0, n - 1, 0, mid);

            if (mx >= val)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (ans != -1)
        {
            st.update(0, 0, n - 1, ans, 0);
        }
        else
        {
            res++;
        }
        return;
    }
    int numOfUnplacedFruits(vector<int> &f, vector<int> &b)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int rem = 0;
        int n = b.size();
        vector<ll> tb(b.begin(), b.end());
        SegmentTree st(n);
        st.build(0, 0, n - 1, tb);
        for (int i = 0; i < n; i++)
        {
            find(f[i], st, n);
        }
        return res;
    }
};