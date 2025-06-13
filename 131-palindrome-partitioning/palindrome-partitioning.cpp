class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palindrome;
        getAllPalindrome(s,palindrome,ans);
        return ans;
    }

    void getAllPalindrome(string s,vector<string>& palindrome,vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back({palindrome});
            return;
        }
        for(int i=0;i<s.size();i++){
            string str=s.substr(0,i+1);
            if(isPalindrome(str)){
                palindrome.push_back(str);
                getAllPalindrome(s.substr(i + 1),palindrome,ans);
                palindrome.pop_back();
            }
        }

    }
    bool isPalindrome(string s){
        string str=s;
        reverse(str.begin(),str.end());
        return s==str;
    }

};