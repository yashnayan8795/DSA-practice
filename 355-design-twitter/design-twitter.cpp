class Twitter {
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    // Constructor
    Twitter() {
        timestamp = 0;
    }

    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        following[userId].insert(userId);  

        for (int followeeId : following[userId]) {
            auto &twts = tweets[followeeId];
            for (int i = max(0, (int)twts.size() - 10); i < (int)twts.size(); i++){
                maxHeap.push(twts[i]);
            }
        }

        vector<int> res;
        for (int i = 0; i < 10 && !maxHeap.empty(); i++){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }

    // Follow a user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    // Unfollow a user
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
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