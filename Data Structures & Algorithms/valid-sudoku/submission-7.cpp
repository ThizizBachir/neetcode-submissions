#include<array>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        std::array<std::array<bool,9>,9> rows={},columns={},boxs={};

        for (int r = 0; r<9;++r){
            for(int c =0 ;c<9;++c){
                char ch = board[r][c];
                if (ch == '.') continue;
                int chIndex = ch - '1';
                int boxIndex = (r/3) * 3 +(c/3);
                if(rows[r][chIndex] || columns[c][chIndex] || boxs[boxIndex][chIndex]){
                    return false;
                }
                rows[r][chIndex] = true;
                columns[c][chIndex] = true;
                boxs[boxIndex][chIndex] = true;
                
            }

        }
            return true;
    
        
    }
};