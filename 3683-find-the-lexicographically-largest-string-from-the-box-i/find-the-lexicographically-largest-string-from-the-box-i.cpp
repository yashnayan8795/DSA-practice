class Solution {
public:
    string answerString(string word, int numFriends) {
       if (numFriends == 1) return word;
        string ans = "";
        int size = word.size();
        int maxChar = word.size() - (numFriends - 1);

        priority_queue<pair<char,int>> pq;

        for (int i = 0; i < word.size(); i++) {
            pq.push({word[i], i});
        }

        char high = pq.top().first;

        while(pq.size() > 0) {
            auto [c, index] = pq.top(); 
            pq.pop();

            if (c != high) break;

            string temp = "";
            for (int i = index; i < min(size, maxChar + index); i++) {
                temp += word[i];
            }

            if (ans < temp) ans = temp;
        }

        return ans;
    }
};