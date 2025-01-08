#include <vector>
#include <string>

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }

private:
    bool isPrefixAndSuffix(const std::string& str1, const std::string& str2) {
        return str2.rfind(str1, 0) == 0 && 
               str2.find(str1, str2.size() - str1.size()) != std::string::npos;
    }
};