class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        else{
            int x= n &(n-1);
            return ((x)== 0);
        }
            
    }
};