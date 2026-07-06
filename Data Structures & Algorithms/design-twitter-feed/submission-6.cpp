class Twitter {
    // we will store user and his tweets with time stamp !!
    unordered_map<int,vector<pair<int,int>>> tweets;
    // we will store user and his followings !!
    // multiple followings to same person is useless !!
    unordered_map<int,unordered_set<int>> following;
    int timer=0;

    // eise nhi hai ki tweet with higher ID is most recent !!!

public:
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        // need to maintain a global timer to store most recent tweets related to this person !!
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // given user jin jin logo ko follow karta hai unke posts with timer will be pushed in pq !!!
        priority_queue<pair<int,int>> pq;

        // everyone should be able to see their own post 
        for(auto it:tweets[userId]){
            pq.push(it);
        }

        // it1 stores the person to whom our user follows !!!
        for(auto it1:following[userId]){
            for(auto it2:tweets[it1]){
                pq.push(it2);
            }
        }
        if(pq.empty()){
            // no tweets related to this userId
            return {};
        }
        // ans ka size should not exceed 10 !!
        vector<int> temp;
        while(!pq.empty() && temp.size()<10){
            // push tweetId
            temp.push_back(pq.top().second);
            pq.pop();
        }
        return temp;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return ;
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return ;
        }
        // now this user no longer follows followeeId
        following[followerId].erase(followeeId);
    }
};
