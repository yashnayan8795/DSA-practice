class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for (int i=left; i<=right;i++) {
            if (i %2==0 && i>2) 
                continue;
            if (isprime(i)) {
                if (!primes.empty() && i<=primes.back()+2) {
                    return {primes.back(),i};
                }
                primes.push_back(i);
            }
        }
        if (primes.size()<2) 
            return {-1,-1};
        vector<int> res(2);
        int minDiff = INT_MAX;
        for (int i=1;i<primes.size(); i++) {
            int diff=primes[i]-primes[i-1];
            if (diff<minDiff) {
                minDiff=diff;
                res[0]=primes[i-1];
                res[1]=primes[i];
            }
        }
        return res;
    }
    bool isprime(int x){
        if(x==1)
            return false;
        for(int i=3;i*i<=x;i+=2){
            if(x% i==0)
                return false;
        }
        return true;
    }
};