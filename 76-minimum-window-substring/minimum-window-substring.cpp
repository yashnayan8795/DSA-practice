class Solution {
public:
    string minWindow(string s, string t) {
        //wordMap, windowMap --> valid then you move left

        unordered_map<char, int> wordMap;
        unordered_map<char, int> windowMap;
        for(char c: t){
            wordMap[c]++;
        }
        int count = t.size();

        int mini = INT_MAX;
        

        int c = 0;
        int l = 0;
        int low = 0;
        for(int r=0; r < s.size(); r++){
            if(wordMap.count(s[r])){
                windowMap[s[r]]++;
                if(windowMap[s[r]] <= wordMap[s[r]]) c++;
            }
            while(c >= count){
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    low = l;
                }

                //cout << s.substr(l, r - l + 1) << '\n';

                if(wordMap.count(s[l])){
                    windowMap[s[l]]--;
                    if(windowMap[s[l]] < wordMap[s[l]]) c--;
                }
                l++;
            }
        }

        if(mini == INT_MAX) return "";
        //cout << low << '\n';
        return s.substr(low, mini);
    }
};