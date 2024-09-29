class Solution {
public:

    string justified(int l,int r,vector<string>& words,int width){
        int sum = 0;
        string s = "";

        for(int i = l;i<=r;i++) sum += words[i].length();
        cout << sum << endl;
        
        if(r != l){
            int sp = (width - sum)/(r-l);
            int rem = (width - sum)%(r-l);

            for(int i = l;i<r;i++){
                s += words[i];
                if(rem > 0){
                    for(int j = 0;j<sp+1;j++) s += " ";
                    rem--;
                }
                else
                    for(int j = 0;j<sp;j++) s += " ";    
            }
            s += words[r];
            return s;
        }
        else{
            int sp = width-sum;
            s += words[l];
            for(int j = 0;j<sp;j++) s += " ";
            return s;
        }

    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(),l = 0,c=0,curr=0;
        bool flag = false;   
        vector<string> ans;

        for(int i = 0;i < n;i++){
            curr += words[i].length();
            cout << "CURR " << curr << endl;
            if(curr > maxWidth){
                cout << "CASE_1" << endl;
                cout << l << " " << i-1 << " " << endl; 
                curr = 0;
                ans.push_back(justified(l,i-1,words,maxWidth));
                l = i;
                i--;
                if(i == n-1){
                    flag = true;
                }
            }
            else if (curr == maxWidth){
                cout << "CASE_2" << endl;
                cout << l << " " << i << " " << endl; 
                curr = 0;
                ans.push_back(justified(l,i,words,maxWidth));
                l = i+1;
            }
            else curr++;
        }

        if(curr > 0 || flag){
            string s = "";

            for(int i = l;i<n;i++){
                s += words[i];
                s += " ";
            }
            int sp = maxWidth - s.length();
            for(int j = 0;j<sp;j++) s += " ";
            ans.push_back(s);
        }
    return ans;
    }
};