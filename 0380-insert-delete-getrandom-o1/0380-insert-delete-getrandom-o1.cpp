class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        return s.insert(val).second;
    }
    
    bool remove(int val) {
        return s.erase(val) ? true : false;
    }
    
    int getRandom() {
        int n = s.size();
        int i = rand() % n;
        auto it = s.begin(); 
        advance(it, i);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */