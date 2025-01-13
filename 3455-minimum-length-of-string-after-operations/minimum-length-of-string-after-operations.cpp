class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> max_freq(26, 0);

        for (int i = 0; i < n; i++) {
            max_freq[s[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (max_freq[i] > 2) {

                if (max_freq[i] & 1) // Odd 
                    count += max_freq[i] - 1;
                else // Even 
                    count += max_freq[i] - 2;
            }
        }

        return n - count;
    }
};