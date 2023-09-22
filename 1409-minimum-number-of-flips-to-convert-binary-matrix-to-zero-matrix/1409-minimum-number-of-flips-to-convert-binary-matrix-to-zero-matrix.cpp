class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        unordered_set<int>st;
        queue<int>q;
        int n=mat.size(),m=mat[0].size();
        int mask=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mask|=(mat[i][j]<<(i*m+j));
            }
        }
        vector<int>dx={-1,0,1,0},dy={0,-1,0,1};
        q.push(mask);
        st.insert(mask);
        int step=0;
        while(!q.empty()){
            // if(q.front()==0)return step;
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                if(curr==0)return step;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        int temp=curr;
                        temp^=(1<<(i*m+j));
                        for(int k=0;k<4;k++){
                            int nr=i+dx[k];
                            int nc=j+dy[k];
                            if(min(nr,nc)>=0 && nr<n && nc<m){
                                temp^=(1<<(nr*m+nc));
                            }
                        }
                        if(st.find(temp)==st.end()){
                            q.push(temp);
                            st.insert(temp);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};