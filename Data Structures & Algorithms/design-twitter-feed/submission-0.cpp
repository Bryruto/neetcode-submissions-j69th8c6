class Twitter {
private:
    vector<pair<int,int>> tweets; //tweetId,userid
    unordered_map<int,unordered_set<int>> follows; //user then all people he follows  

public:
    Twitter(){}
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        follows[userId].insert(userId);

        vector<int> top10;
        for(int i = static_cast<int>(tweets.size()-1);i >= 0 && top10.size() < 10;i--){
            int tmp = tweets[i].second;
            if(follows[userId].contains(tmp)){
                top10.push_back(tweets[i].first);
            } 
        }
        return top10;
    }
    
    void follow(int userId, int follow) {
        follows[userId].insert(follow); 
    }
    
    void unfollow(int userId, int followeeId) {
        follows[userId].erase(followeeId);
    }


};
