class Solution {
private:  
    bool ok(vector<vector<char>>& board,int i,int j){
        int sr=(i/3)*3;
        int er=((i/3)+1)*3;
        int sc=(j/3)*3;
        int ec=((j/3)+1)*3;
        for(int r=0;r<9;r++){
            if(board[r][j]==board[i][j] && r!=i){
                return false;
            }
        }
        for(int r=0;r<9;r++){
            if(board[i][r]==board[i][j] && r!=j){
                return false;
            }
        }
        for(int a=sr;a<er;a++){
            for(int b=sc;b<ec;b++){
                if(a!=i && b!=j && board[a][b]==board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board,int i,int j){
        if(i==9){
            return true;
        }
        int nr,nc;
        if (j==8){
            nr=i+1;
            nc=0;
        }
        else{
            nr=i;
            nc=j+1;
        }
        if(board[i][j]!='.'){
            if(sudoku(board,nr,nc)){
                return true;
            }
        }
        else{
            for(char c='1';c<='9';c=(char)(c+1)){
                board[i][j]=c;
                if(ok(board,i,j)){
                if( sudoku(board,nr,nc)){
                    return true;
                }
                }
                board[i][j]='.';
            }
        }
        return false;
    }
public:
    bool solveSudoku(vector<vector<char>>& board) {
        return sudoku(board,0,0);
        // return board;
    }
};