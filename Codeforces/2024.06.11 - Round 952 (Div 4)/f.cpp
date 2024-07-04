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
        int maxHealth, attacks;
        cin >> maxHealth >> attacks;
        vector<int> damages(attacks);
        int totalDamage = 0;
        for (int i = 0; i < attacks; i++)
        {
            cin >> damages[i];
            totalDamage += damages[i];
        }
        vector<int> cooldown(attacks);
        for (int i = 0; i < attacks; i++)
        {
            cin >> cooldown[i];
        }
        if (totalDamage >= maxHealth)
        {
            cout << 1 << endl;
            continue;
        }
    }
    return 0;
}