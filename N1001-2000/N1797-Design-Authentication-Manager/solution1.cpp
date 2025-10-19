class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> mp;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (mp.count(tokenId) && mp[tokenId] > currentTime) {
            mp[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto &[_, time] : mp) {
            if (time > currentTime) {
                res++;
            }
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
