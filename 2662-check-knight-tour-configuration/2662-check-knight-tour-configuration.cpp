class Solution {
    vector<int>dx={-2,-1,1,2,2,1,-1,-2},dy={1,2,2,1,-1,-2,-2,-1};
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return false;
        }
        int n=grid.size();
        int count=0;
        int next=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            count++;
            next++;
            grid[x][y]=-1;
            for(int i=0;i<8;i++){
                int nr=x+dx[i];
                int nc=y+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]!=-1){
                    if(grid[nr][nc]==next){
                        q.push({nr,nc});
                        break;
                    }
                }
            }    
        }
        cout<<count<<endl;
        if(count==(n*n)){
            return true;
        }
        return false;


    }
};