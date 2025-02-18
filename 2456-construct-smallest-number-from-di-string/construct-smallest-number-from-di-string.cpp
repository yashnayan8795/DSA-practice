class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        for (int i = 1; i <= n + 1; i++) {
            num.push_back(i + '0'); 
        }
        while (true) {
            bool isValid = true;
            for (int i = 0; i < n; i++) {
                if ((pattern[i]== 'I' && num[i]> num[i + 1])||(pattern[i] == 'D' && num[i] < num[i + 1])) {
                    isValid =false;
                    break;
                }
            }
            if (isValid) return num;
            next_permutation(num.begin(), num.end());
        }


        // stack<char> st;
        // string result="";
        // int n = pattern.size()+1;
        // for(int i=1;i<=n;i++){
        //     st.push(i+'0');
        //     if(i==n||pattern [i-1]=='I'){
        //         while(!st.empty()){
        //             result +=st.top();
        //             st.pop();
        //         }
        //     }
        // }
        // return result;
    }
    
};