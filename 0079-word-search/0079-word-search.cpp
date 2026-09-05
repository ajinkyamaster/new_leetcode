class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, string word, int len){
        
        if(len==word.size()) return true;
        
        int drow[] ={0, -1, 0, +1};
        int dcol[] = {+1, 0, -1, 0};

        int n = board.size();
        int m = board[0].size();

        for(int k=0;k<4;k++){
            int nr = i+drow[k];
            int nc = j+dcol[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==word[len]){
                 char temp = board[nr][nc];
                    board[nr][nc] = '#';

                    if(check(board, nr, nc, word, len+1)) {
                        return true;
                    }

                    board[nr][nc] = temp;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == word[0]) {

                    char temp = board[i][j];
                    board[i][j] = '#';

                    if(check(board, i, j, word, 1)) {
                        return true;
                    }

                    board[i][j] = temp;
                }
            }
        }
        return false;

    }
};