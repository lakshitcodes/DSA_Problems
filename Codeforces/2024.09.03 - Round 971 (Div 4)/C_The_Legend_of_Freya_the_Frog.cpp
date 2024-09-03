#include <bits/stdc++.h>
using namespace std;

/*
C. The Legend of Freya the Frog
time limit per test2 seconds
memory limit per test256 megabytes
Freya the Frog is traveling on the 2D coordinate plane. She is currently at point (0,0) and wants to go to point (x,y). In one move, she chooses an integer d such that 0≤d≤k and jumps d spots forward in the direction she is facing.

Initially, she is facing the positive x
 direction. After every move, she will alternate between facing the positive x direction and the positive y direction (i.e., she will face the positive y
 direction on her second move, the positive x direction on her third move, and so on).
What is the minimum amount of moves she must perform to land on point (x,y)?

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.
Each test case contains three integers x, y, and k (0≤x,y≤109,1≤k≤109).

Output
For each test case, output the number of jumps Freya needs to make on a new line.
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
        cin >> i;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int rx = ceil((double)x / k);
        int ry = ceil((double)y / k);
        if (rx == ry)
        {
            cout << rx + ry - 1 << endl;
        }
        else if (ry > rx)
        {
            cout << 2 * ry << endl;
        }
        else
        {
            cout << 2 * rx - 1 << endl;
        }
    }
    return 0;
}