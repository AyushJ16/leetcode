class Solution {
    vector<int>dp;
    vector<int>vis;
private:    
    int helper(int i,vector<int>&b){

        if(i==(b.size()-1)){
            return 0;
        }
        vis[i]=1;
        if(dp[i]!=-1){
            return dp[i];
        }
        int steps=100000;
        int ceil=min((int)b.size()-1,i+6);
        for(int k=i+1;k<=ceil;k++){
            int t=100000;
            
            if(b[k]==-1){
                if(vis[k]==0)
                t=1+helper(k,b);
            }
            else{
                if(vis[b[k]]==0){
                    t=1+helper(b[k],b);
                }
            }
            steps=min(t,steps);
        }
        return dp[i]=steps;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n=board.size();
        vector<int>b(n*n+1);
        int cnt=1;
        int f=1;
        // int f1,f2;
        for(int i=n-1;i>=0;i--){
            if(f==1){
                for(int j=0;j<n;j++){
                    int num=cnt;
                    cnt++;
                    b[num]=board[i][j];
                }
                f=0;
                continue;
            }
            if(f==0){
                for(int j=n-1;j>=0;j--){
                    int num=cnt;
                    cnt++;
                    b[num]=board[i][j];
                }
                f=1;
            }
        }
        if(b[1]==1){
            cout<<"o"<<endl;
            return -1;
        }
        dp.resize((n*n)+1,-1);
        vis.resize((n*n)+1,0);
        queue<pair<int,int>>q;
        q.push({1,0});
        vis[1]=1;

        while(!q.empty()){
            auto[curr,moves]=q.front();
            cout<<curr<<" "<<moves<<" "<<b[curr]<<endl;
            q.pop();
            if(curr==(n*n)){
                return moves;
            }
            int ceil=min((int)b.size()-1,curr+6);
            for(int i=curr+1;i<=ceil;i++){
                {
                    cout<<i<<" "<<b[i]<<endl;
                    if(b[i]!=-1 && !vis[b[i]]){
                        cout<<curr<<" "<<b[i]<<endl;
                        vis[b[i]]=1;
                        q.push({b[i],moves+1});
                    }
                    else if(!vis[i] && b[i]==-1){
                        cout<<"kutta "<<curr<<" "<<i<<endl;
                        vis[i]=1;
                        q.push({i,moves+1});
                    }
                }
            }

        }
        return -1;

        // int ans= helper(1,b);
        // cout<<ans<<endl;
        // if(ans==100000)
        // return -1;
        // return ans;
    }
};