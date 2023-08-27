class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> pos(n);
        if(n==1 || (n==2 && stones[1]==1)){
            return true;
        }
        if(stones[1]!=1){
            return false;
        }
        pos[1].push_back(1);
        pos[1].push_back(2);
        bool f=false;
        for(int i=2;i<n;i++){
            f=false;
            for(int j=1;j<i;j++){
                // if((stones[j]-stones[i]) > stones[j]+1){
                //     continue;
                // }
                    if(stones[i]-stones[j]  > stones[j]+1){
                        continue;
                    }
                for(auto &jumps:pos[j]){
                    if(jumps+stones[j]==stones[i]){
                        cout<<i<<" "<<j<<" "<<jumps<<endl;
                        pos[i].push_back(stones[i]-stones[j]);
                        pos[i].push_back(stones[i]-stones[j]-1);
                        pos[i].push_back(stones[i]-stones[j]+1);
                        f=true;
                        break;
                    }
                }
            }
        }if(pos[n-1].size()>0)
        return true;
        return false;

    }
};