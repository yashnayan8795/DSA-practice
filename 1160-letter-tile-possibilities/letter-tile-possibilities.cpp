class Solution {
public:

    void solve(unordered_map<char,int>& f,int &count){
        for (auto& [ch, num] : f) {
            if (num > 0) {
                count++;
                num--;
                solve(f, count);
                num++;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        
        unordered_map<char,int> f;
        for(char c: tiles){
            f[c]++;
        }
        
        int count = 0;
        solve(f, count);
        return count;
    }
};