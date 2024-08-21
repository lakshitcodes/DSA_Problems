#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START148B/problems/FIGBOT

bool canBobWin(int N, int X, int Y, const string &S)
{
    int aliceX = 0, aliceY = 0;
    int bobX = X, bobY = Y;

    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'L')
            aliceX--;
        else if (S[i] == 'R')
            aliceX++;
        else if (S[i] == 'U')
            aliceY++;
        else if (S[i] == 'D')
            aliceY--;

        int distance = abs(bobX - aliceX) + abs(bobY - aliceY);
        int timePassed = i + 1;

        if (distance <= timePassed && (timePassed - distance) % 2 == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, X, Y;
        string S;
        cin >> N >> X >> Y;
        cin >> S;

        if (canBobWin(N, X, Y, S))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
