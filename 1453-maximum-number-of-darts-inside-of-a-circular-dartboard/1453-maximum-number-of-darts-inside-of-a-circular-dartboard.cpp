\static inline double d2(double x1, double y1, double x2, double y2) { return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 -y2); }

class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        #define EPS 0.141
        int R = r * r;
        int D = 4 * R;
        int max_cnt = 1;
        for (int i = 0; i < darts.size(); i++) {
            for (int j = i + 1; j < darts.size(); j++) {
                int ds = d2(darts[i][0], darts[i][1], darts[j][0], darts[j][1]);
                if (ds <= D + EPS) {
                    double midpointx, midpointy;
                    midpointx = darts[i][0] + (darts[j][0] - darts[i][0]) / 2.0;
                    midpointy = darts[i][1] + (darts[j][1] - darts[i][1]) / 2.0;

                    #define NOT_THERE 10001
                    double centerx1 = NOT_THERE, centery1 = NOT_THERE;
                    double centerx2 = NOT_THERE, centery2 = NOT_THERE;
                    if (ds == R) {
                        centerx1 = midpointx;
                        centery1 = midpointy;
                        centerx2 = midpointx;
                        centery2 = midpointy;
                    } else {
                        double distpx = (darts[i][0] - darts[j][0]) / 2.0;
                        double distpy = (darts[i][1] - darts[j][1]) / 2.0;

                        double ortho_distpx = -distpy;
                        double ortho_distpy = distpx;
                        double ortho_d = sqrt(d2(0.0, 0.0, ortho_distpx, ortho_distpy));

                        double ortho_distpx_norm = ortho_distpx / ortho_d;
                        double ortho_distpy_norm = ortho_distpy / ortho_d;

                        int d = sqrt(R - ds/4.0);

                        centerx1 = midpointx + d * ortho_distpx_norm;
                        centery1 = midpointy + d * ortho_distpy_norm;
                        centerx2 = midpointx - d * ortho_distpx_norm;
                        centery2 = midpointy - d * ortho_distpy_norm;
                    }
                    int cnt1 = 0;
                    int cnt2 = 0;
                    for (int k = 0; k < darts.size(); k++) {
                        if (d2(centerx1, centery1, darts[k][0], darts[k][1]) <= R + EPS) {
                            cnt1++;
                        }
                        if (d2(centerx2, centery2, darts[k][0], darts[k][1]) <= R + EPS) {
                            cnt2++;
                        }
                    }
                    max_cnt = max(max_cnt, max(cnt1, cnt2));
                }
            }
        }
        return max_cnt;
    }
};