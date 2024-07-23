#include <bits/stdc++.h>
using namespace std;

/*
A. Diagonals
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vitaly503 is given a checkered board with a side of n and k chips. He realized that all these k chips need to be placed on the cells of the board (no more than one chip can be placed on a single cell).

Let's denote the cell in the i-th row and j-th column as (i,j). A diagonal is the set of cells for which the value i+j
 is the same. For example, cells (3,1), (2,2), and (1,3) lie on the same diagonal, but (1,2) and (2,3) do not. A diagonal is called occupied if it contains at least one chip.

Determine what is the minimum possible number of occupied diagonals among all placements of k chips.

Input
Each test consists of several sets of input data. The first line contains a single integer t (1≤t≤500) — the number of sets of input data. Then follow the descriptions of the sets of input data.

The only line of each set of input data contains two integers n, k (1≤n≤100,0≤k≤n2) — the side of the checkered board and the number of available chips, respectively.

Output
For each set of input data, output a single integer — the minimum number of occupied diagonals with at least one chip that he can get after placing all k
 chips.
*/

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define take(arr)       \
    for (auto &i : arr) \
    {                   \
        cin >> i;       \
    }

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (b == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        int diagLen = a;
        while (b > 0)
        {
            if (diagLen == a)
            {
                ans++;
                if (b >= diagLen)
                {
                    b -= diagLen;
                }
                else
                {
                    b = 0;
                }
            }
            else
            {
                if (b >= 2 * diagLen)
                {
                    b -= 2 * diagLen;
                    ans += 2;
                }
                else if (b >= diagLen)
                {
                    b -= diagLen;
                    ans += 1;
                }
                else if (b < 2 * diagLen && b > diagLen)
                {
                    b = 0;
                    ans += 2;
                }
                else
                {
                    b = 0;
                    ans++;
                }
            }
            diagLen--;
        }
        cout << ans << endl;
    }
    return 0;
}