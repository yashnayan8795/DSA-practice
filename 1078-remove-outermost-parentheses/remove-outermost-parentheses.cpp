class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='('){
                if(st.empty())  s[i] = '0';
                st.push(ch);
            }else{
                st.pop();
                if(st.empty()) 
                    s[i]='0';
            }
        }
        string ans;
        for(auto ch : s){
            if(ch != '0')   
                ans.push_back(ch);
        }
        return ans;
    }
};