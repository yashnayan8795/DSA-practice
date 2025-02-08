class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mpp;

    NumberContainers() {}

    void change(int index, int number) {
        if (mp.count(index)) {
            int o=mp[index];
            if (o!=number) {
                mpp[o].push(index);
            }
        }

        mp[index]=number;
        mpp[number].push(index);
    }

    int find(int number) {
        if (!mpp.count(number)) {
            return -1;
        }

        auto& pq=mpp[number];
        while (!pq.empty()) {
            int id =pq.top();
            if (mp[id]==number) { 
                return id;
            }
            pq.pop();// yaha par galat index ko remove karege
        }

        return -1;

    }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */