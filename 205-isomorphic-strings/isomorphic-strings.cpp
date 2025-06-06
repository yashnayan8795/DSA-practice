class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char,char> mapp;
        unordered_set<char> c;
        for(int i = 0; i < s.length(); ++i){
            char str1=s[i];
            char str2=t[i];
            if(mapp.count(str1)){
                if(mapp[str1]!=str2) return false;
            
            }else{
                if(c.count(str2)) return false;
                mapp[str1]=str2;
                c.insert(str2);
            }

        }
        return true;
    }
};