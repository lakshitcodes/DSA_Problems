#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/design-twitter/

class Twitter
{
    class User
    {
    public:
        int userId;
        unordered_set<int> followers;
        unordered_set<int> following;
        vector<pair<int, int>> posts;
        User(int id)
        {
            userId = id;
        }
    };

private:
    unordered_map<int, User *> users;
    int time;

public:
    class comparator
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first < b.first;
        }
    };
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        User *user;
        if (users.count(userId))
        {
            user = users[userId];
        }
        else
        {
            user = new User(userId);
            users[userId] = user;
        }
        time++;
        user->posts.push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        if (users.find(userId) == users.end())
            return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (auto tweet : users[userId]->posts)
        {
            pq.push(tweet);
        }
        for (auto followeeId : users[userId]->following)
        {
            for (auto tweet : users[followeeId]->posts)
            {
                pq.push(tweet);
            }
        }
        vector<int> ans;
        for (int i = 0; i < 10 && !pq.empty(); i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        User *user1, *user2;
        if (users.count(followerId))
        {
            user1 = users[followerId];
        }
        else
        {
            user1 = new User(followerId);
            users[followerId] = user1;
        }
        if (users.count(followeeId))
        {
            user2 = users[followeeId];
        }
        else
        {
            user2 = new User(followeeId);
            users[followeeId] = user2;
        }
        user2->followers.insert(followerId);
        user1->following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (users.find(followerId) == users.end() || users.find(followeeId) == users.end())
            return;
        User *follower = users[followerId];
        User *followee = users[followeeId];
        follower->following.erase(followeeId);
        followee->followers.erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
