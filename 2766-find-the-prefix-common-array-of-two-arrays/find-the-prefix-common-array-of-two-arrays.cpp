class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        unordered_map<int, int> x;

        int count = 0;
        for(int i = 0; i < n; i++) {
            x[A[i]]++;
            if(x[A[i]] == 2) {
                count++;
            }

            x[B[i]]++;
            if(x[B[i]] == 2) {
                count++;
            }

            result[i] = count;
        }

        return result;
    }
};