class Solution {
public:
    static bool ops(vector<int>&a,vector<int>&b){
        return (a[1]<b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),ops);
        int ans=0;
        int le=-1e5;
        for(int i=0;i<intervals.size();i++){

            int e=intervals[i][1];
            int s=intervals[i][0];
            // cout<<s<<" "<<e<<endl; 
            if(s>=le){
                le=e;
                continue;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};