// Difficulty: Medium | Time: O(k log k) feed, O(1) other | Space: O(U + T) | Pattern: Design | Use: Merging k chronological user timelines into a recent activity feed
class Twitter {
public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        struct Entry {
            int time;
            int tweetId;
            int uid;
            int idx;
            bool operator<(const Entry& o) const { return time < o.time; }
        };

        priority_queue<Entry> pq;
        auto pushLatest = [&](int uid) {
            auto it = tweets.find(uid);
            if (it != tweets.end() && !it->second.empty()) {
                int idx = (int)it->second.size() - 1;
                pq.push({it->second[idx].first, it->second[idx].second, uid, idx});
            }
        };

        pushLatest(userId);
        if (auto fit = following.find(userId); fit != following.end()) {
            for (int followee : fit->second) {
                pushLatest(followee);
            }
        }

        vector<int> feed;
        while (!pq.empty() && (int)feed.size() < 10) {
            Entry top = pq.top();
            pq.pop();
            feed.push_back(top.tweetId);
            if (top.idx > 0) {
                const auto& list = tweets[top.uid];
                pq.push({list[top.idx - 1].first, list[top.idx - 1].second, top.uid, top.idx - 1});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (auto it = following.find(followerId); it != following.end()) {
            it->second.erase(followeeId);
        }
    }

private:
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
