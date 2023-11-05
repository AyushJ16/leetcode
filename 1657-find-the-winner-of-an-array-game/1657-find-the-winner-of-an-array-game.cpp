class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int pos=0;
        int maxi=-1;
        for(auto nums:arr){
            mp[pos]=nums;
            maxi=max(maxi,nums);
            pos++;
        }
        int wins=0;
        int winner=-1;
        int f=0,s=1;
        for(int i=1;i<arr.size();i++){
            if(mp[f]>mp[s]){
                if(winner!=mp[f]){
                    winner=mp[f];
                    wins=1;
                }
                else{
                    wins++;
                }
                mp[++pos]=mp[s];
                s++;
            }
            else if(mp[f]<mp[s]){
                if(winner!=mp[s]){
                    winner=mp[s];
                    wins=1;
                }
                else{
                    wins++;
                }
                mp[++pos]=mp[f];
                f=s;
                s++;
            }
            cout<<wins<<" "<<winner<<endl;
            if(wins==k){
                return winner;
            }
        }
        return maxi;
        return 0;
    }
};