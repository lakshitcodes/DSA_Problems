#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/design-movie-rental-system/

using int2 = pair<int, int>;       // price,shop
using int3 = tuple<int, int, int>; // price,shop,movie
class MovieRentingSystem
{
public:
    unordered_map<long long, int> Shop;  // (shop,movie)->price
    unordered_map<int, set<int2>> Movie; // movie->set(price,shop)
    set<int3> rented;                    // rented->set(price,shop,movie)

    static inline long long key(int shop, int movie)
    {
        return (long long)shop << 30 | movie;
    }
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            Shop[key(shop, movie)] = price;
            Movie[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> ans;
        auto &S = Movie[movie];
        int i = 0;
        for (auto it = S.begin(); it != S.end() && i < 5; it++, i++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }

    void rent(int shop, int movie)
    {
        int price = Shop[key(shop, movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = Shop[key(shop, movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; it++, i++)
        {
            auto [price, shop, movie] = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */