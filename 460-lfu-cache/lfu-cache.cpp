class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq;  
    unordered_map<int, list<int>> freqToKeys; 
    unordered_map<int, list<int>::iterator> keyToIter; 

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end())
            return -1;

        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;


        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }


        freq++;
        freqToKeys[freq].push_back(key);
        keyToIter[key] = --freqToKeys[freq].end();

        keyToValFreq[key].second = freq;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {

            keyToValFreq[key].first = value;
            get(key);  
            return;
        }

        if (keyToValFreq.size() == capacity) {
            int lruKey = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if (freqToKeys[minFreq].empty())
                freqToKeys.erase(minFreq);
            keyToValFreq.erase(lruKey);
            keyToIter.erase(lruKey);
        }

        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_back(key);
        keyToIter[key] = --freqToKeys[1].end();
        minFreq = 1;
    }
};
