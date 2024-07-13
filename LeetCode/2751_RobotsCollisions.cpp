#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/robot-collisions/description

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;

        for (int i = 0; i < n; i++)
        {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<tuple<int, int, char, int>> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty() || get<2>(st.top()) == get<2>(robots[i]))
            {
                st.push(robots[i]);
            }
            else
            {
                while (!st.empty() && get<2>(st.top()) == 'R' && get<2>(robots[i]) == 'L')
                {
                    if (get<1>(st.top()) < get<1>(robots[i]))
                    {
                        get<1>(robots[i])--;
                        st.pop();
                    }
                    else if (get<1>(st.top()) == get<1>(robots[i]))
                    {
                        st.pop();
                        get<1>(robots[i]) = -1;
                        break;
                    }
                    else
                    {
                        get<1>(st.top())--;
                        get<1>(robots[i]) = -1;
                        break;
                    }
                }
                if (get<1>(robots[i]) > 0)
                {
                    st.push(robots[i]);
                }
            }
        }

        vector<int> ans;
        vector<pair<int, int>> survivors;

        while (!st.empty())
        {
            auto robot = st.top();
            st.pop();
            survivors.push_back({get<1>(robot), get<3>(robot)});
        }

        sort(survivors.begin(), survivors.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        for (auto &survivor : survivors)
        {
            ans.push_back(survivor.first);
        }

        return ans;
    }
};
