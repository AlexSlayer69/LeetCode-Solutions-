class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        vector<int> v;
        int n = 0;
        while(num > 0){
            v.push_back(num%10);
            num /= 10;
            n++;
        }
        reverse(v.begin(),v.end());

        for(int i =0;i < n;i++){
            if((n-i) == 4){
                int j = 0;
                while(j < v[i]){
                    s += 'M';
                    j++;
                } 
            }
            else if((n-i) == 3){
                if(v[i] == 9){
                    s += "CM";
                    v[i] = 0;
                }
                else if(v[i] >= 5){
                    s += 'D';
                    v[i] -= 5;
                }
                else if(v[i] == 4){
                    s += "CD";
                    v[i] = 0;
                }
                int j = 0;
                while(j < v[i]){
                    s += 'C';
                    j++;
                }
            }
            else if((n-i) == 2){
                if(v[i] == 9){
                    s += "XC";
                    v[i] = 0;
                }
                else if(v[i] >= 5){
                    s += 'L';
                    v[i] -= 5;
                }
                else if(v[i] == 4){
                    s += "XL";
                    v[i] = 0;
                }
                int j = 0;
                while(j < v[i]){
                    s += 'X';
                    j++;
                }
            }
            else if((n-i) == 1){
                if(v[i] == 9){
                    s += "IX";
                    v[i] = 0;
                }
                else if(v[i] >= 5){
                    s += 'V';
                    v[i] -= 5;
                }
                else if(v[i] == 4){
                    s += "IV";
                    v[i] = 0;
                }
                int j = 0;
                while(j < v[i]){
                    s += 'I';
                    j++;
                }
            }
        }
        return s;
    }
};