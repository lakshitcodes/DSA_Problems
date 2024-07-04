#include <bits/stdc++.h>
using namespace std;

/*

A. Catch the Coin
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Monocarp visited a retro arcade club with arcade cabinets. There got curious about the "Catch the Coin" cabinet.

The game is pretty simple. The screen represents a coordinate grid such that:

the X-axis is directed from left to right;the Y-axis is directed from bottom to top;the center of the screen has coordinates (0,0).
At the beginning of the game, the character is located in the center, and n coins appear on the screen — the i-th coin is at coordinates (xi,yi). The coordinates of all coins are different and not equal to (0,0).

In one second, Monocarp can move the character in one of eight directions. If the character is at coordinates (x,y), then it can end up at any of the coordinates (x,y+1), (x+1,y+1), (x+1,y), (x+1,y−1), (x,y−1), (x−1,y−1), (x−1,y), (x−1,y+1).

If the character ends up at the coordinates with a coin, then Monocarp collects that coin.

After Monocarp makes a move, all coins fall down by 1, that is, they move from (x,y) to (x,y−1). You can assume that the game field is infinite in all directions.

Monocarp wants to collect at least one coin, but cannot decide which coin to go for. Help him determine, for each coin, whether he can collect it.

Input
The first line contains a single integer n (1≤n≤500) — the number of coins.

In the i-th of the next n lines, two integers xi and yi (−50≤xi,yi≤50) are written — the coordinates of the i-th coin. The coordinates of all coins are different. No coin is located at (0,0).

Output
For each coin, print "YES" if Monocarp can collect it. Otherwise, print "NO".
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (y < -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}