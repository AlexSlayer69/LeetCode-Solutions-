class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int h = n;
        for(int i =0;i<n;i++){
            if(citations[i] < h) h--;
        }
        return h;
    }
};