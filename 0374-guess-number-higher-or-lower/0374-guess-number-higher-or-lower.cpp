/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long low = 1,high = n;
        long med = (low + high)/2;
        while(guess(med) != 0){
            if(guess(med) == 1){
                low = med+1;
            }
            else{
                high = med-1;
            }
            med = (low+high)/2;
            
        }
        return med;
    }
};