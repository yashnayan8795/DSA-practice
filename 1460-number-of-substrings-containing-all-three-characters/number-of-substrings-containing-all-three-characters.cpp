class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mp;
        int result = 0;
        int i = 0;
        int j = 0;
        int n = s.size();

        while (j < n) {
            mp[s[j]]++;
            while (mp.size()==3) {
                mp[s[i]]--;
                if (mp[s[i]]==0)
                    mp.erase(s[i]);
                result+=n-j;  
                i++;
            }
            j++;
        }

        return result;
    }
};
