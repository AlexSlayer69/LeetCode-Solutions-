class SmallestInfiniteSet {
public:
    set<int> pq;
    int border;
    SmallestInfiniteSet() {
        pq.insert(1);
        border = 1;
    }
    
    int popSmallest() {
        int el = *(pq.begin());
        pq.erase(el);
        if(pq.empty()) border++;
        pq.insert(border);
        return el;
    }
    
    void addBack(int num) {
        if(num < border) pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */