#include <iostream>
#include <algorithm>
using namespace std;

/*
B. Card Game
time limit per test2 seconds
memory limit per test256 megabytes
Suneet and Slavic play a card game. The rules of the game are as follows:
Each card has an integer value between 1 and 10.
Each player receives 2 cards which are face-down (so a player doesn't know their cards).
The game is turn-based and consists exactly of two turns. In a round, both players pick a random unflipped card and flip it. The player who flipped a card with a strictly greater number wins the round. In case of equality, no one wins the round.
A player wins a game if he wins the most number of rounds (i.e. strictly greater than the other player). In case of equality, no one wins the game.
Since Suneet and Slavic aren't best friends, you need to calculate the number of ways the game could happen that Suneet would end up as the winner.

For a better understanding, please check the notes section.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The first and only line of each test case contains 4 integers a1, a2, b1, b2 (1≤a1,a2,b1,b2≤10) where a1 and a2 represent the cards Suneet has, and b1 and b2 represent the cards Slavic has, respectively.

Output
For each test case, output a single integer — the number of games Suneet would win considering all possible games.
*/

int countSuneetWins(int a1, int a2, int b1, int b2)
{
    int winCount = 0;

    int suneetCards[] = {a1, a2};
    int slavicCards[] = {b1, b2};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                if (k == i)
                    continue;
                for (int l = 0; l < 2; ++l)
                {
                    if (l == j)
                        continue;
                    int suneetWins = 0, slavicWins = 0;
                    if (suneetCards[i] > slavicCards[j])
                        ++suneetWins;
                    else if (suneetCards[i] < slavicCards[j])
                        ++slavicWins;

                    if (suneetCards[k] > slavicCards[l])
                        ++suneetWins;
                    else if (suneetCards[k] < slavicCards[l])
                        ++slavicWins;

                    if (suneetWins > slavicWins)
                        ++winCount;
                }
            }
        }
    }

    return winCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        cout << countSuneetWins(a1, a2, b1, b2) << '\n';
    }

    return 0;
}
