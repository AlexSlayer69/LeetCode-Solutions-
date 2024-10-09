class Solution {
public:
   int dij(unordered_map<int, vector<pair<int, int>>> &god, vector<int> &dist, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int node = pq.top().second;     
        pq.pop();
        
        if (node == n * n) {
            return curr_dist;
        }

        for (auto neighbor : god[node]) {
            int neighbor_node = neighbor.second;
            int edge_weight = neighbor.first;
            int new_dist = curr_dist + edge_weight;
            if (new_dist < dist[neighbor_node]) {
                dist[neighbor_node] = new_dist;
                pq.push({new_dist, neighbor_node});
            }
        }
    }
    return -1;
}

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int l = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);

        for (int row = n - 1; row >= 0; row--) {
            for (auto col : columns) {
                cells[l++] = {row, col};
            }
            reverse(columns.begin(), columns.end());
        }


        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto [row, col] = cells[next];
                int d = board[row][col] != -1 ? board[row][col] : next;
                if (dist[d] == -1) {
                    dist[d] = dist[curr] + 1;
                    q.push(d);
                }
            }
        }
        return dist[n*n];
    }
};