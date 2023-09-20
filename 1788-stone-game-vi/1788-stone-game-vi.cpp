class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<tuple<int,int,int>>pq;
        for(int i=0;i<aliceValues.size();i++){
            pq.push({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
            // pq2.push({bobValues[i],aliceValues[i]});

        }
        int chance=1;
        int ans=0;
        // map<pair<int,int>,int>mp;
        while(chance<=aliceValues.size()){
            if(chance%2==1){
                // while(mp[{pq1.top().first,pq1.top().second}]==1){
                //     pq1.pop();
                // }
                ans+=get<1>(pq.top());
                // mp[{pq1.top().second,pq1.top().first}]=1;
                pq.pop();
            }
            else{
                // while(mp[{pq2.top().first,pq1.top().second}]==1){
                //     pq2.pop();
                // }
                ans-=get<2>(pq.top());
                // mp[{pq2.top().second,pq2.top().first}]=1;
                pq.pop();

            }
            chance++;
        }
        if(ans==0){
            return 0;
        }
        return ans>0?1:-1;
    }
};