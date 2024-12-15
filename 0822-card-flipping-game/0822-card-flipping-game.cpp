class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int r=INT_MAX;
        set<int>s;
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]==backs[i])
            s.insert(fronts[i]);
        }
        for(int i=0;i<fronts.size();i++){
            if(s.count(fronts[i])==0) 
            r=min(r,fronts[i]);
        }
        for(int i=0;i<fronts.size();i++){
            if(s.count(backs[i])==0) 
            r=min(r,backs[i]);
        }
        if(r==INT_MAX) return 0;
        else return r;
    }
};