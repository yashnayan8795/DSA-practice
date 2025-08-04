class Solution {
public:
    string minWindow(string& s, string& t) {
        if(t.size() > s.size()) return "";

        vector<int> wordMap(256);
        vector<int> windowMap(256);
        int total = t.size();
        int count = 0;

        for(char c: t){
            wordMap[c]++;
        }

        int l = 0;
        int mini = INT_MAX;
        int low = 0;
        for(int r=0; r<s.size(); r++){
            char c = s[r];
            if(wordMap[c] > 0){
                windowMap[c]++;
                if(windowMap[c] <= wordMap[c]) count++;
            }
            while(count == total){
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    low = l;
                }

                char lc = s[l];
                if(wordMap[lc] > 0 ){
                    windowMap[lc]--;
                    if(windowMap[lc] < wordMap[lc]) count--;
                }

                l++;
            }
        }

        if(mini == INT_MAX) return "";
        return s.substr(low, mini);
    }
};