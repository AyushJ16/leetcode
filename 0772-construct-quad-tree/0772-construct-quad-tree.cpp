/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool isSame(vector<vector<int>>& grid, int x, int y, int len){
        for(int xl = 0; xl < len; ++xl){
            for(int yl = 0; yl < len; ++yl){
                if(grid[x + xl][y +yl] != grid[x][y]){
                    return false;
                }
            }
        }
        return true;
    }
    Node* dfs(vector<vector<int>>& grid,int x,int y,int len){
        if(len==0){
            return nullptr;
        }
        if(len ==1 || isSame(grid,x,y,len)){
            auto n=new Node(grid[x][y],true);
            return n;
        }
        auto node = new Node(0, false);
        int half = len/2;
        node->topLeft = dfs(grid, x, y, half);
        node->topRight = dfs(grid, x , y+ half, half);
        node->bottomLeft = dfs(grid, x+ half, y , half);
        node->bottomRight = dfs(grid, x + half, y + half, half);

        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return nullptr;
        }
        return dfs(grid,0,0,grid.size());

    }

};