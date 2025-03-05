class Solution {
public:
    long long coloredCells(int n) {
        // long long x= n*n ;    //69675 * 69675 nahi hua isspe
        // long long y=(n - 1) * (n - 1);
        // long long res=x+y;

        // return res;

        return (long long)n*n + (long long) (n - 1) * (n - 1);
    }
};