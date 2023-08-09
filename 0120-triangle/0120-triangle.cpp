class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev=triangle[n-1];
        cout<<prev[0]<<endl;
        for(int i=n-2;i>=0;i--){
            vector<int>curr(triangle[i].size(),1e5);
            // cout<<triangle[i].size()<<endl;
            for(int j=triangle[i].size()-1;j>=0;j--){
                curr[j]=min(triangle[i][j]+prev[j+1],triangle[i][j]+prev[j]);
                // cout<<j<<" "<<curr[j];
            }
            // cout<<endl;
            prev=curr;
        }
        return prev[0];
    }
};