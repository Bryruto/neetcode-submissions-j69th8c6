class Solution {
public:
    bool checkInclusion(string s1, string s2) {
 
        if (s1.size() > s2.size()) return false;

        sort(s1.begin(), s1.end());

        for (size_t i = 0; i + s1.size() <= s2.size(); i++) {
            string sub = s2.substr(i, s1.size());
            sort(sub.begin(), sub.end());

            if (sub == s1) return true;
        }

        return false;
    }
};
