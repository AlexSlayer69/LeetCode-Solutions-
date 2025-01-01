class Solution {
public:
  string alphabetBoardPath(string target) {
    vector<vector<string>>table(26,vector<string>(26));
    
    for(int i = 0; i != 26; i++)
      for(int j = i+1, k = i/j; j != 26; j++){
        int dy = j/5 - i/5, dx = j%5 - i%5;
        table[i][j] = (dx > 0? string(dx,'R') : string(-dx,'L')) + string(dy,'D');
        table[j][i] = string(dy,'U') + (dx > 0? string(dx,'L') : string(-dx,'R'));
      }
    
    string answer;
    for(int i = 0, j = 0, k; j != target.size(); i = k)
      answer += table[i][k = target[j++] - 'a'] + '!';
    
    return answer;
  }
};