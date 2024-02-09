class Solution {
public:
    unordered_set <char> ans_row;
    unordered_set <char> ans_col;
    unordered_set <char> ans_square;

    bool isValidSudoku(vector<vector<char>>& board) {
        // Idea: 把陣列內的數全做and，若結果為true即有重複
        
        for(int i = 0; i < board[0].size(); i++){
            ans_row.clear();ans_col.clear();ans_square.clear();
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j]!='.'){
                    if(ans_row.count(board[i][j])){
                        return false;
                    }
                    else {
                        ans_row.insert(board[i][j]);
                    }
                }
                if(board[j][i]!='.'){
                    if(ans_col.count(board[j][i])){
                        return false;
                    }
                    else {
                        ans_col.insert(board[j][i]);
                    }
                }
                 if(board[((i/3)*3 + j/3)][((i%3)*3) + j%3]!='.'){
                    if(ans_square.count(board[((i/3)*3 + j/3)][((i%3)*3) + j%3])){
                        return false;
                    }
                    else {
                        ans_square.insert(board[((i/3)*3 + j/3)][((i%3)*3) + j%3]);
                    }
                 }
            }
        }
        return true;
    }
};
