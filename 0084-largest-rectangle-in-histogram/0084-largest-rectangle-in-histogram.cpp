class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        vector<int> starts(n,0);
        vector<int> ends(n,0);

        stack<int> s;
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                starts[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
            }
        
        while(!st.empty()){
            starts[st.top()] = 0;
            st.pop();
        }

        for(int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                ends[st.top()] = i - 1;
                st.pop();
            };
            st.push(i);
        }

        while(!st.empty()) {
            ends[st.top()] = n - 1;
            st.pop();
        }

        for (int i = 0; i < n; i++) {
            int width = ends[i] - starts[i] + 1;
            area = max(max_area, heights[i] * width);
        }
        return area;
    }
};