class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto aster : asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !st.empty() && st.back() > 0) {
                alive = st.back() < -aster;
                if (st.back() <= -aster) {
                    st.pop_back();
                }
            }
            if (alive) {
                st.push_back(aster);
            }
        }
        return st;
    }
};
