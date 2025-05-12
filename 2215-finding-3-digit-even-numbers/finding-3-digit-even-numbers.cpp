class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int digitCount[10] = {};  
        for (int d: digits) {
            digitCount[d]++;
        }
        vector<int> result;

        for (int num=100;num<= 998;num += 2) {
            int temp = num;
            int usedDigits[10] = {};
            
            usedDigits[temp % 10]++; temp /= 10;
            usedDigits[temp % 10]++; temp /= 10;
            usedDigits[temp]++;
            bool c = true;
            for (int i = 0; i < 10; ++i) {
                if (usedDigits[i] > digitCount[i]) {
                    c = false;
                    break;
                }
            }
            if (c) {
                result.push_back(num);
            }
        }
        return result;
    }
};
