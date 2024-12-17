class Solution {
    private: 
    int value(vector<int>& tops, vector<int>& bottoms, int vll) {
        int n = tops.size();
        int cnt = 0;

        for(int i = 0; i<n; i++) {
            if(tops[i] == vll) continue;
            else if(bottoms[i] == vll) cnt++;
            else {
                return INT_MAX;
            }
        }

        return cnt;
    }
    int value1(vector<int>& tops, vector<int>& bottoms, int vll) {
        int n = tops.size();
        int cnt = 0;

        for(int i = 0; i<n; i++) {
            if(bottoms[i] == vll) continue;
            else 
            
            if(tops[i] == vll) cnt++;
            else {
                return INT_MAX;
            }
        }

        return cnt;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int m = bottoms.size();

        if (n != m)
            return -1;

            int ans1 = INT_MAX;
            int ans2 = INT_MAX;

        for (int i = 1; i <= 6; i++) {
            ans1 = min(ans1 , value(tops, bottoms, i));
            ans2 = min(ans2 , value1(tops, bottoms, i));
            cout<<ans1<<" "<<ans2<<'\n';
        }

        return (ans1 == INT_MAX && ans2 == INT_MAX) ? -1 : min(ans1, ans2);
    }
};