class Solution {
public:
    
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        
        int ah=0;
        for(int &C: piles){
            ah+= C/givenHour;

            if(C%givenHour != 0)
                ah++;
        }
        
        return ah <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n= piles.size();
        int l= 1;
        int r= *max_element(begin(piles), end(piles));
        while(l<r){
            int mid= l+(r-l)/2;
            if(canEatAll(piles,mid,h)){
                r= mid;
            }else{
                l= mid+1;
            }
        }
        return l;
    }
};