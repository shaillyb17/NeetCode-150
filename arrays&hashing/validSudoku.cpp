#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char,int> rows[9],columns[9],boxes[9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char ch = board[i][j];
            if(ch!='.' && (rows[i][ch]++>0 || columns[j][ch]++>0 || boxes[i/3 * 3 + j/3][ch]++>0))
                return false;
        }
    }
    return true;    
}

int main(){
    int n;	cin >> n;
    vector<vector<char>> board(9, vector<char>(9));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    cout << isValidSudoku(board);
    return 0;
}