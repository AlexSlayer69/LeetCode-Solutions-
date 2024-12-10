class Solution {
public:
    bool canIWinDFSHelper(int runningSum, int maxChoosable, int target, int currState, vector<int>& gameState) {

        if(gameState[currState] != 0)   return (gameState[currState] > 0);

        for(int num=1; num<= maxChoosable; num++) {

            int numMask = 1 << (num-1);
            bool numAvailable = !(currState & numMask);
            if(numAvailable) {

                int nextState = currState | numMask;
                
                bool wonNow = (runningSum + num) >= target;
                bool opponentWon = canIWinDFSHelper(runningSum + num, maxChoosable, target, nextState, gameState);

                if(wonNow || !opponentWon) {
                    gameState[currState] = 1;
                    return true;
                }
            }
        }
        gameState[currState] = -1;
        return false;
    }
    bool canIWin(int maxChoosable, int target) {

        if(target < maxChoosable)       return true;
        
        int achievableSum = maxChoosable * (maxChoosable + 1) / 2;
        if(achievableSum < target)      return false;

        // [1, n] : states = n bits [0 0 0 0 ... 0 0] = each number taken status
        // 0    = number not taken
        // 1    = number taken and I won
        // -1   = number taken and opponent won
        int totalStates = (1 << maxChoosable);
        vector<int> gameState(totalStates, 0);  

        int initialState = 0;       // No numbers picked
        return canIWinDFSHelper(0, maxChoosable, target, initialState, gameState);
    }
};
