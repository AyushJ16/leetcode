class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector <int> prev(m+1,0);
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> curr(m+1,0);
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0'){
                    curr[j+1]=0;
                }
                else{
                    curr[j+1]=min(prev[j],min(prev[j+1],curr[j]))+1;
                    ans=max(ans,curr[j+1]);
                }
            }
            prev=curr;
        }
        return ans*ans;

    }
};