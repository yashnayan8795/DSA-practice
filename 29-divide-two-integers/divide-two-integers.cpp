class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == divisor) return 1; 
        //bool sign=true;
        bool sign = (dividend > 0) == (divisor > 0);

        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long que = 0;

        while (n >=d) {
            int cnt =0;
            while (n>=(d<<(cnt + 1))) {
                cnt++;
            }
            que += (1<<cnt);
            n -= (d<<cnt); 
        }

        //if(que >=(pow(2,31)+1) && sign==true)
        if (que >= INT_MAX + 1LL && !sign)
            return INT_MIN;
        if(que >=INT_MAX && sign)
            return INT_MAX;

        return sign ? que : -que;
    }
};
