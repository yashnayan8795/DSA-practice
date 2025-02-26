class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int maxm_sum = INT_MIN, max_ending_here = 0; 
        int size = a.size();
        for (int i = 0; i < size; i++) 
        { 
            max_ending_here += a[i]; 
            maxm_sum = max(maxm_sum, max_ending_here); 
            if (max_ending_here < 0) 
                max_ending_here = 0; 
        }  

        int min_ending_here = 0, minm_sum = INT_MAX; 

        for (int i=0; i<size; i++) 
        { 
            min_ending_here += a[i]; 
            minm_sum = min(minm_sum, min_ending_here);  
            if(min_ending_here > 0)
                min_ending_here = 0;
        } 

        return max(abs(maxm_sum), abs(minm_sum)); 
    }
};