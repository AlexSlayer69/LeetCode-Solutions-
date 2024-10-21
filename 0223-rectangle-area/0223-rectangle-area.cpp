class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        pair<int,int> range1x = {ax1,ax2};
        pair<int,int> range1y = {ay1,ay2};
        pair<int,int> range2x = {bx1,bx2};
        pair<int,int> range2y = {by1,by2};
        
        bool x_int = false;
        if(range1x.first <= range2x.first && range1x.second > range2x.first) 
            x_int = true;
        else if(range1x.second >= range2x.second && range1x.first < range2x.second) 
            x_int = true;
        else if(range2x.first <= range1x.first && range2x.second > range1x.first) 
            x_int = true;
        else if(range2x.second >= range1x.second && range2x.first < range1x.second) 
            x_int = true;    

        bool y_int = false;
        if(range1y.first <= range2y.first && range1y.second > range2y.first) 
            y_int = true;
        else if(range1y.second >= range2y.second && range1y.first < range2y.second) 
            y_int = true;
        else if(range2y.first <= range1y.first && range2y.second > range1y.first) 
            y_int = true;
        else if(range2y.second >= range1y.second && range2y.first < range1y.second) 
            y_int = true;


        //cout << x_int << " " << y_int << endl;

        if(!(x_int && y_int)){
            return (abs(range1x.first - range1x.second) * abs(range1y.first - range1y.second))
            + (abs(range2x.first - range2x.second) * abs(range2y.first - range2y.second));
        }        
        else{
            int rangex = 0;
            int rangey = 0;
            // 4 cases 
            if(range1x.first <= range2x.first && range2x.first <= range1x.second 
                && range1x.second <= range2x.second){
                rangex = abs(range2x.first - range1x.second);
            }
            else if(range1x.first <= range2x.first &&  range2x.second <= range1x.second){
                rangex = abs(range2x.first - range2x.second);
            }
            else if(range2x.first <= range1x.first && range1x.first <= range2x.second 
                && range2x.second <= range1x.second){
                rangex = abs(range1x.first - range2x.second);
            }
            else if(range2x.first <= range1x.first && range1x.second <= range2x.second){
                rangex = abs(range1x.first - range1x.second);
            }

            // 4 cases 
            if(range1y.first <= range2y.first && range2y.first <= range1y.second 
                && range1y.second <= range2y.second){
                rangey = abs(range2y.first - range1y.second);
            }
            else if(range1y.first <= range2y.first &&  range2y.second <= range1y.second){
                rangey = abs(range2y.first - range2y.second);
            }
            else if(range2y.first <= range1y.first && range1y.first <= range2y.second 
                && range2y.second <= range1y.second){
                rangey = abs(range1y.first - range2y.second);
            }
            else if(range2y.first <= range1y.first && range1y.second <= range2y.second){
                rangey = abs(range1y.first - range1y.second);
            }    
        return (abs(range1x.first - range1x.second) * abs(range1y.first - range1y.second))
            + (abs(range2x.first - range2x.second) * abs(range2y.first - range2y.second)) 
            - (rangex * rangey);
        }
    }
};