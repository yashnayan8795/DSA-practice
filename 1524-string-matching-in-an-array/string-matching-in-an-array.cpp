class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int x = words.size();
        vector<string> a;

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    a.push_back(words[i]);
                    break;
                }
            }
        }

        return a;
    }
};