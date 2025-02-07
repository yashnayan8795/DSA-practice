class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;

        for (size_t i = 0; i < queries.size(); i++) {
            int pos = queries[i][0], c = queries[i][1];

            if (ball.count(pos)) {
                if (--color[ball[pos]] == 0) {
                    distinct--;
                }
            }

            ball[pos] = c;

            if (++color[c] == 1) {
                distinct++;
            }

            ans.push_back(distinct);
        }
        return ans;
    }
};
