#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lfu-cache/description/

// How this Works
//  1. We will use 3 data structures
//  2. keyVal : It will store the key and value of the key
//  3. freqList : It will store the frequency of the key
//  4. pos : It will store the position of the key in the freqList
//  5. minFreq : It will store the minimum frequency of the key
//  6. In the constructor, we will initialize the capacity and minFreq to 0
//  7. In the get function, we will check if the key is present in the keyVal or not
//  8. If it is not present, we will return -1
//  9. If it is present, we will erase the key from the freqList and increment the frequency of the key
//  10. We will push the key in the freqList with the new frequency and update the position of the key in the pos
//  11. If the freqList with the minimum frequency is empty, we will increment the minFreq
//  12. In the put function, we will check if the capacity is 0 or not
//  13. If it is 0, we will return
//  14. If the key is already present in the keyVal, we will update the value of the key
//  15. We will erase the key from the freqList and increment the frequency of the key
//  16. We will push the key in the freqList with the new frequency and update the position of the key in the pos
//  17. If the freqList with the minimum frequency is empty, we will increment the minFreq
//  18. If the size of the keyVal is equal to the capacity, we will erase the key with the minimum frequency
//  19. We will insert the new key in the keyVal with the value and frequency as 1
//  20. We will push the key in the freqList with the frequency as 1 and update the position of the key in the pos
//  21. We will update the minFreq to 1

class LFUCache
{
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyVal;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        if (keyVal.find(key) == keyVal.end())
        {
            return -1;
        }
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if (freqList[minFreq].empty())
        {
            minFreq++;
        }
        return keyVal[key].first;
    }

    void put(int key, int value)
    {
        if (!capacity)
        {
            return;
        }
        if (keyVal.find(key) != keyVal.end())
        {
            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if (freqList[minFreq].empty())
            {
                minFreq++;
            }
            return;
        }
        if (keyVal.size() == capacity)
        {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */