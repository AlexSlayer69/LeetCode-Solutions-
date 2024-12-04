class Solution {
public:
    const int dir[5] = {0, -1, 0, 1, 0};
    void floodFill(int i, int j, vector<vector<int>>& image, set<pair<int, int>> &vis, int color, int curColor){
        vis.insert(make_pair(i,j));
        image[i][j] = color;
        for(int d=0;d<4;d++){
            int x = i+dir[d], y = j+dir[d+1];
            if(x<0 || y<0 || x>=image.size() || y>=image[0].size() || image[x][y] != curColor)continue;
            if(vis.find(make_pair(x,y)) == vis.end())floodFill(x,y,image, vis, color, curColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        set<pair<int, int>> vis;
        int curColor = image[sr][sc];
        floodFill(sr, sc, image, vis, color, curColor);
        return image;
    }
};