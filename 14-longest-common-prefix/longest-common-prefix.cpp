class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string pre= strs[0];
        int i=0;
        while(i<strs.size()){
            int j=0;
            while(j<pre.length() && j<strs[i].length() && pre[j] == strs[i][j]) j++;

            pre= pre.substr(0,j);
            if(pre=="") return "";

            i++;
        }
        return pre;
    }
};