class Solution {
private:
    string num;
    int n;
    long long tg;
    vector<string> ans;

    void dfs(const string& path, long long prev, long long total, int pos) {
        if (pos == n) {
            if (total == tg) ans.push_back(path);
            return;
        }

        for (int i = pos; i < n; ++i) {
            if (i > pos && num[pos] == '0') break; // prevent leading zeros
            long long cur = stoll(num.substr(pos, i - pos + 1));

            if (pos == 0) {// first number: no operator
                dfs(to_string(cur), cur, cur, i + 1);
            } else {
                dfs(path + "+" + to_string(cur),  cur,        total + cur,               i + 1);
                dfs(path + "-" + to_string(cur), -cur,        total - cur,               i + 1);
                dfs(path + "*" + to_string(cur),  prev * cur, total - prev + prev * cur, i + 1);
            }
        }
    }

public:
    std::vector<std::string> addOperators(std::string s, int target) {
        num = std::move(s);
        n = (int)num.size();
        tg = target;
        ans.clear();
        dfs("", 0, 0, 0);
        return ans;
    }
};
