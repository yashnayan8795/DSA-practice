class SmallestInfiniteSet {
public:
    int curr;
    set<int> seq;
    SmallestInfiniteSet() {
        seq.clear();
        curr=1;
    }
    
    int popSmallest() {
       if (!seq.empty()) {
            int y = *seq.begin();
            seq.erase(seq.begin());
            return y;
        } else {
            return curr++;
        }
    }
    
    void addBack(int num) {
        if(num < curr) seq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */