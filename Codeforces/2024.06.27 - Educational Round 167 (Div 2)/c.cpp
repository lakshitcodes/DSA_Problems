#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a)
        {
            cin >> i;
        }
        for (auto &i : b)
        {
            cin >> i;
        }
        int ratinga = 0, ratingb = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                ratinga += a[i];
            }
            else if (a[i] < b[i])
            {
                ratingb += b[i];
            }
            else
            {
                if (a[i] == -1)
                {
                    if (ratinga > ratingb)
                    {
                        ratinga += a[i];
                    }
                    else
                    {
                        ratingb += b[i];
                    }
                }
                else if (ratinga > ratingb)
                {
                    ratingb += b[i];
                }
                else
                {
                    ratinga += a[i];
                }
            }
        }
        cout << min(ratinga, ratingb) << endl;
    }
    return 0;
}