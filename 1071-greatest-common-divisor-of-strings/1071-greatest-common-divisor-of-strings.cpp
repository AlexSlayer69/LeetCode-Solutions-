class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string x;
        int leng = 0;
        if( str1 + str2 == str2 + str1)
        {
            for (int i = 1 ; i <= str1.length() ; i++ )
            {
                if ( str1.length() % i == 0 && str2.length() % i == 0)
                {
                    leng = i;
                }
            }

            x = str1.substr(0 , leng);

        }
        else {
            return "";
        }

        return x;
    }
};