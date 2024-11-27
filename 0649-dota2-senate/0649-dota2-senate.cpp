class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int Rcount = 0,Dcount = 0;
        for(auto it : senate) {
            if(it == 'R') Rcount++;
            else Dcount++;
        }
        vector<bool> vis(senate.size(),false);
        int r = n-1,d = n-1;
        for(int k = 0;k<n;k++){
            //cout << vis[k] << endl;
            if(vis[k]) continue;
            else{
                if(senate[k] == 'R') {
                    while(d >= 0 && senate[d] != 'D') d--;
                    if(d >= 0){
                        vis[d] = true;
                        d--;
                        Dcount--;
                    }
                    if(Rcount > Dcount) return "Radiant";
                }
                else{
                    while(r >= 0 && senate[r] != 'R') r--;
                    if(r >= 0){
                        vis[r] = true;
                        r--;
                        Rcount--;
                    }
                    if(Rcount < Dcount) return "Dire";
                }
            }
        }
        return (Rcount > Dcount) ? "Radiant" : "Dire";
    }
};