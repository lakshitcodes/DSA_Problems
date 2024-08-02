#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lru-cache/

class Node
{
public:
    int key, value;
    Node *next, *prev;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache
{
private:
    void insertAtFront(Node *element)
    {
        element->next = head->next;
        head->next->prev = element;
        head->next = element;
        element->prev = head;
    }
    void deleteAtPos(Node *element)
    {
        element->prev->next = element->next;
        element->next->prev = element->prev;
    }

public:
    unordered_map<int, Node *> mp;
    int capacity;
    Node *head, *tail;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        mp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *element = mp[key];
        deleteAtPos(element);
        insertAtFront(element);
        return element->value;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            mp[key]->value = value;
            deleteAtPos(mp[key]);
            insertAtFront(mp[key]);
            return;
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *toDelete = tail->prev;
                mp.erase(toDelete->key);
                deleteAtPos(toDelete);
                delete (toDelete);
            }
            Node *newElement = new Node(key, value);
            mp[key] = newElement;
            insertAtFront(newElement);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */