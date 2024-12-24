class Solution {
public:

void lpsfind(vector<int>&lps,string s){
	    int pref = 0 , suf = 1 ;
	    while(suf < s.size()){
	        if(s[pref] == s[suf]){
	            lps[suf]=pref+1;
	            suf++;
	            pref++;
	        }
	        else{
	            if(pref == 0){
	                lps[suf] = 0;
	                suf++;
	            }
	            else{
	                pref = lps[pref -1];
	            }
	        }
	    }
}


    bool strStr(string haystack, string needle) {

       vector<int>lps(needle.size(),0);
       lpsfind(lps,needle);

       int first = 0 , second = 0;

       while(first < haystack.size() && second < needle.size()){
           if(haystack[first] == needle[second]){
               first++ , second++;
           }
           else{
               if(second == 0){
                   first++;
               }
               else{
                   second = lps[second -1];
               }
           }
       }

       if(second == needle.size()){
           return true;;
       }
       else{
           return false;
       }

    }




    int repeatedStringMatch(string a, string b) {

        if(a == b){
            return 1;
        }

        string st = a;
        int repeat = 1;

        while(st.length()<b.length()){
            st += a;
            repeat++;
        }

        if(strStr(st,b)==true){
            return repeat;
        }
    
        if(strStr(st+a,b)==true){
            return repeat+1;
        }
        else{
            return -1;
        }



    }
};