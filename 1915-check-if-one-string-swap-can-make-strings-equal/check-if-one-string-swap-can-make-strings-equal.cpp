class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        int count_s1[26] = {};
        int count_s2[26] = {};

        for(int i = 0; i < n; ++i) {
            count_s1[s1[i] - 'a']++;
            count_s2[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; ++i)
            if(count_s1[i] != count_s2[i])
                return false;

        int diff = 0;
        for(int i = 0; i < n; ++i) 
            diff += s1[i] != s2[i] ? 1 : 0;

        return diff <= 2;
    }
};