class Solution {
public:
    long long mod=1000000007;
    int countGoodNumbers(long long n) {
        
        long long odd=n/2;
        long long even = (n+1)/2;
       return (power(5, even) * power(4, odd)) % mod;

    }
    long long power(long long x,long long y){
        long long ans=1;
        //base case
        if(y==0) 
            return ans;
        
        ans=power(x,y/2);
        // ans*=ans;
        // ans%=mod;
        ans=(ans*ans)%mod;
        if(y%2)
            ans=(ans*x)%mod;
         //   ans*=x;
        // ans%=mod;

        return ans;
    }
};