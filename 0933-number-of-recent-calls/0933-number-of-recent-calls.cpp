class RecentCounter {
public:
    int i;
    int j;
    vector<int> records = vector<int>(10000,0);
    RecentCounter() {
        i = 0;
        j = 0;
    }
    
    int ping(int t) {
        while(i < j && (t - records[i] > 3000)){
            i++;
        }
        records[j] = t;
        j++;
        return j - i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */