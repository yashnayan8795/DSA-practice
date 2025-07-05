class Solution {
public:
    int findLucky(vector<int>& arr) {
        make_heap(begin(arr), end(arr));
        int cnt = 1, last = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr.front() == last)
                ++cnt;
            else {
                if (last == cnt)
                    return cnt;
                last = arr.front();
                cnt = 1;
            }
            pop_heap(arr.begin(), arr.end() - i);
        }
        return arr.front() == cnt ? cnt : - 1;    
    }
};