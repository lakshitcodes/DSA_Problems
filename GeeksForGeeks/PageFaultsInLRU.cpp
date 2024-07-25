#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

class Solution
{
public:
    bool find(vector<int> &memory, int page)
    {
        for (auto &i : memory)
        {
            if (page == i)
            {
                return true;
            }
        }
        return false;
    }
    void erase(vector<int> &memory, int page)
    {
        int idx = -1;
        for (int i = 0; i < memory.size(); i++)
        {
            if (page == memory[i])
            {
                idx = i;
                break;
            }
        }
        memory.erase(memory.begin() + idx);
        return;
    }
    int pageFaults(int N, int C, int pages[])
    {
        int faults = 0;
        vector<int> memory;

        for (int i = 0; i < N; i++)
        {
            bool finder = find(memory, pages[i]);

            if (finder)
            {
                erase(memory, pages[i]);
            }
            else
            {
                if (memory.size() >= C)
                {
                    memory.erase(memory.begin());
                }
                faults++;
            }
            memory.push_back(pages[i]);
        }
        return faults;
    }
};