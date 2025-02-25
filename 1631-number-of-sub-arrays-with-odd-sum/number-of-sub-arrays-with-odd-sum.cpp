class Solution {
public:
    const int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
    //     int count = 0;
    //     for (int i=0; i<n;i++) {
    //         int sum = 0;
    //         for (int j=i;j<n;j++) {
    //             sum += arr[j];
    //             if (sum%2!= 0) {
    //                 count=(count+1)%M;
    //             }
    //         }
    //     } 
    //     return count % M;
    // }
        int count=0;
        int sum=0;
        int odd= 0;
        int even = 1;
        for(int i=0; i<n;i++) {
            sum += arr[i];
            if(sum%2==0) { //odd + even = odd
                count = (count +odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count+ even) % M;
                odd++;
            }
        }
        return count;
    }

};