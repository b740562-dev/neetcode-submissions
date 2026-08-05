class Twitter {
    int timer;
    // mpp1 stores a user and his tweets according to time !!!
    unordered_map<int, vector<pair<int, int>>> tweets;
    // mpp2 stores a user and the ones to whom he follows (his followees)!!!
    unordered_map<int, unordered_set<int>> followee;
    struct Node {
        int time;
        int tweetId;
        int user;
        int idx;
    };

    struct comp {
        bool operator()(Node& a, Node& b) { return a.time < b.time; }
    };

   public:
    Twitter() { timer = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer, tweetId});
        timer++;
    }

    vector<int> getNewsFeed(int userId) {
        // can do using max heap !!!
        priority_queue<Node, vector<Node>, comp> pq;
        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
        }
        for (auto& f : followee[userId]) {
            if (!tweets[f].empty()) {
                int idx = tweets[f].size() - 1;
                pq.push({tweets[f][idx].first, tweets[f][idx].second, f, idx});
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            // no first second now !!!
            int time = pq.top().time;
            int tweet = pq.top().tweetId;
            int curr = pq.top().user;
            int idx = pq.top().idx;
            pq.pop();
            ans.push_back(tweet);
            if (idx >= 1) {
                pq.push({tweets[curr][idx - 1].first, tweets[curr][idx - 1].second, curr, idx - 1});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        followee[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followee[followerId].find(followeeId) == followee[followerId].end()) {
            return;
        }
        followee[followerId].erase(followeeId);
    }
};
