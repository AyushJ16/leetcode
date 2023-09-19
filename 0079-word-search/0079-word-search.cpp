class Solution {
    bool DFS(int i, int j, int idx, vector<vector<char>>& board,string &word)
    {
        if(idx == word.length()) return true;
        
        if(i< 0 || j < 0 || i > board.size()-1 || j > board[i].size() -1 || board[i][j] != word[idx]) return false;
         
        char currChar = board[i][j];
        board[i][j] = ' ';
        bool found = DFS(i-1, j, idx+1, board,word) ||
                     DFS(i, j-1, idx+1, board,word) ||
                     DFS(i+1, j, idx+1, board,word) ||
                     DFS(i, j+1, idx+1, board,word);
        
        board[i][j] = currChar;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // if(board) return false;
        if(word == "") return true;
        
        // this.word = word;
        
        for(int i =0; i<board.size(); i++)
        {
            for(int j =0; j < board[i].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                   if(DFS(i, j, 0, board,word)) return true;
                }
            }
        }
        return false;
    }
};