#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START142B/problems/ARRREM

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[i] = a;
        }

        int j = 0;
        for (j = 0; j < 32; j++)
        {
            int aur = 0;
            for (int i = 0; i < n; i++)
            {

                int bit = 1 << j;
                bit = bit & arr[i];

                aur = aur | bit;
            }
            if (aur == 0)
            {
                break;
            }
        }

        vector<bool> toDelete(n, false);
        while (j < 32)
        {
            for (int i = 0; i < n; i++)
            {
                int bit = 1 << j;
                bit = bit & arr[i];
                if (bit > 0)
                {
                    toDelete[i] = true;
                }
            }
            j++;
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (toDelete[i] == true)
                count++;
        }
        cout << count << endl;
    }
}