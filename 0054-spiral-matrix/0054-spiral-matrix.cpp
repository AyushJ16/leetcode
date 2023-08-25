class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int r=matrix.size(),c=matrix[0].size(),row=0,col=0;
        int v=101;
        ans.push_back(matrix[0][0]);
        vector<int> dx={0,1,0,-1},dy={1,0,-1,0};
        matrix[0][0]=v;
        int direction=0;
        int dc=0;
        while(ans.size()<(r*c)){
            int nr=row+dx[direction];
            int nc=col+dy[direction];
            while(nr>=0 && nr<r && nc>=0 && nc<c && matrix[nr][nc]!=v){
                ans.push_back(matrix[nr][nc]);
                // dc=0;
                matrix[nr][nc]=v;
                row=nr;
                col=nc;
                nr=row+dx[direction];
                nc=col+dy[direction];
            }
            direction=(direction+1)%4;
            // dc++;
            // direction%=4;
        }
        return ans;
    }
};