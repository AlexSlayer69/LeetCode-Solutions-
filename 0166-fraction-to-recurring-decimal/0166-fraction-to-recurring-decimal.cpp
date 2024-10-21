class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int,int> pre;
        bool flag = false;
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            flag = true;
        }
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        long rem = num%den;
        long q  = num/den;
        string s = "";
        s += to_string(q);
        if(rem == 0){
            if(flag) s.insert(s.begin(),'-');
            return s;
        }
        s += ".";
        int i = s.size();
        while(rem && pre.find(rem) == pre.end()){
            pre[rem] = i;
            rem *= 10;
            while(rem < den){
                rem *= 10;
                s += "0";
                i++;
            }
            q = rem/den;
            rem %= den;
            s += to_string(q); 
            i++;
        }
        if(rem == 0){
            if(flag) s.insert(s.begin(),'-');
            return s;
        }
        if(pre.find(rem) != pre.end()){
            s.insert(s.begin()+pre[rem],'(');
            s.push_back(')');
        }
        
        if(flag) s.insert(s.begin(),'-');
        return s;
    }
};