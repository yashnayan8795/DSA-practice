class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(begin(p), end(p));
        sort(begin(t), end(t));
        int j = 0;
        for (int i = 0; i < t.size() && j < p.size(); ++i)
            j += p[j] <= t[i];
        return j;
    }
};