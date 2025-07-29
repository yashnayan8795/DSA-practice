class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        unordered_map<string, bool> memo;
        return canConstruct(s, wordset, memo); 
    }

private:
    bool canConstruct(const string& target, unordered_set<string>& wordSet, unordered_map<string, bool>& memo) {
        if (memo.find(target) != memo.end())
            return memo[target];

        if (target.empty())
            return true;

        for (const string& word : wordSet) {
            if (target.find(word) == 0) {  
                string suffix = target.substr(word.length());
                if (canConstruct(suffix, wordSet, memo)) {
                    memo[target] = true;
                    return true;
                }
            }
        }

        memo[target] = false;
        return false;
    }
};
