class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int win_size = s1.length();
        int s2_len = s2.length();

        if(win_size > s2_len) return false;

        vector<int> s1_(26, 0), s2_(26, 0);

        for(int i = 0; i < win_size; i++){
            s1_[s1[i] - 'a']++;
            s2_[s2[i] - 'a']++;
        }

        if(s1_ == s2_) return true;

        for(int i = win_size; i < s2_len; i++){
            s2_[s2[i] - 'a']++;
            s2_[s2[i - win_size] - 'a']--;

            if(s1_ == s2_) return true;
        }

        return false;
    }
};
