class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(char c = 'A'; c <= 'Z'; c++)
        {
            int i = 0;
            int j = 0;
            int r = 0;
            while(j < n)
            {
                if(s[j] == c)
                    j++;
                else if(r < k){
                    j++;
                    r++;
                }
                else if(s[i] == c)
                    i++;
                else{
                    i++, 
                    r--;
                }
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};