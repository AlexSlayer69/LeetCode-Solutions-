class Solution {
public:

    string add(string a, string b){
        int n = a.size() , m = b.size() ;
        int i = 0,j = 0;
        int carry = 0;
        string res = "";
        while(i<n || j<m){
            int temp = carry;
            if(i<n) temp += a[i++] - '0';
            if(j<m) temp += b[j++] - '0';
            carry = temp/10;
            res += (temp%10)+'0';
        }
        while(carry){   
            res += (carry%10)+'0';   
            carry /= 10;
        }
        return res;
    }

    string multiply(string num1, string num2) {
        int n = num1.size(),m = num2.size();
        string ans = "";
        if(n == 1 && num1[0] == '0' || m == 1 && num2[0] == '0') return "0";
        for(int i = n-1; i>=0;i--){
            int carry = 0;
            string a = "";
            for(int k = 0;k<n-i-1;k++) a += '0';
            for(int j = m-1;j>=0;j--){
                int prod = ((num1[i] - '0') * (num2[j] - '0')) + carry;
                carry = prod/10; 
                if(prod > 9) prod %= 10;
                a += (prod + '0');
            }
            while(carry){
                a += (carry%10) + '0';
                carry /= 10;
            }
            ans = add(a,ans);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};