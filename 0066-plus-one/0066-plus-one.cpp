class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        digits[n-1]++;
        if(digits[n-1] > 9){
            carry = 1;
            digits[n-1] %= 10;
        } 
        for(int i = n-2;i>=0;i--){
            if(carry == 0) break;
            digits[i] += carry; 
            carry = 0;
            if(digits[i] > 9){
                carry = 1;
                digits[i] %= 10;
            } 
        }
        if(carry == 1){
            digits.insert(digits.begin(),1);
            return digits;
        }
        else return digits;
    }
};