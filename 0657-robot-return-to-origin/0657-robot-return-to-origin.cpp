class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0, horizontal = 0;
        
        for (char c: moves) {
            if (c == 'U') vertical++;
            if (c == 'D') vertical--;

            if (c == 'R') horizontal++;
            if (c == 'L') horizontal--;
        }

        return vertical == 0 && horizontal == 0;
    }
};