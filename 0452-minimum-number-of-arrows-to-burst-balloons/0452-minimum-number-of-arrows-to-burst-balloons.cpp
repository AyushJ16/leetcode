class Solution {
public:
    static bool ops(vector<int>&a,vector<int>&b){
        return (a[1]<b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),ops);
        int ans=0;
        int le=INT_MIN;
        for(int i=0;i<points.size();i++){
            // if(i==0){

            // }
            int e=points[i][1];
            int s=points[i][0];
            // cout<<s<<" "<<e<<endl; 
            if(s>le || i==0){
                le=e;
                continue;
            }
            else{
                ans++;
            }
        }
        return points.size()-ans;
    }
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
};