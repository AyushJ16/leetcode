class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,double>>ewage(n);
        for(int i=0;i<n;i++){
            ewage[i]={1.0*wage[i]/(1.0*quality[i]),(double)quality[i]};
        }
        sort(ewage.begin(),ewage.end());
        double qsum=0,res=DBL_MAX;
        priority_queue<double>pq;
        for(int i=0;i<n;i++){
            qsum+=ewage[i].second;
            pq.push(ewage[i].second);
            if(pq.size()>k)qsum-=pq.top(),pq.pop();
            if(pq.size()==k)res=min(res,qsum*ewage[i].first);


        }
        return res;
        
    }
};