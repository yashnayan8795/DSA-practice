class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length()<2){
            return "";
        }
        
        unordered_set<int> mapp;

        for(char c: s){
            mapp.insert(c);
        }
        for(int i=0;i<s.length();i++){
            char c = s[i];

            if(mapp.count(tolower(c))&& mapp.count(toupper(c))) 
                continue;
        
            string l= longestNiceSubstring(s.substr(0,i));

            string r= longestNiceSubstring(s.substr(i+1));
        

            return l.length()>=r.length()?l:r;
        }
        return s;
    }
};