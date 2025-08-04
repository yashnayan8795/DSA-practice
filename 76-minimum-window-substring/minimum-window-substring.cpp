class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> wordMap;
        unordered_map<char, int> windowMap;
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
            if(wordMap.count(c)){
                windowMap[c]++;
                if(windowMap[c] <= wordMap[c]) count++;
            }
            while(count == total){
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    low = l;
                }

                char lc = s[l];
                if(wordMap.count(lc)){
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