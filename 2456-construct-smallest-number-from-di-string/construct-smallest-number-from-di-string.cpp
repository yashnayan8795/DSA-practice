class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string result="";
        int n = pattern.size()+1;
        for(int i=1;i<=n;i++){
            st.push(i+'0');
            if(i==n||pattern [i-1]=='I'){
                while(!st.empty()){
                    result +=st.top();
                    st.pop();
                }
            }
        }
        return result;
    }
    
};