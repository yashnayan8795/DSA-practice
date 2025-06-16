class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        solve(result, curr, n);
        return result;
    }

    void solve(vector<string>& result, string curr, int n) {
        if (curr.length() == 2 * n) {
            if (isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        solve(result, curr + "(", n);
        solve(result, curr + ")", n);
    }

    bool isValid(string str) {
        int counter = 0;
        for (char c : str) {
            if (c == '(') counter++;
            else if (c == ')') counter--;
            if (counter < 0) return false; // more ')' than '('
        }
        return counter == 0; // must be balanced
    }
};
