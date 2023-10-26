class Solution {
map<int,int>mp;
int mod=1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i =0;i<arr.size();i++){
            mp[arr[i]]=1;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(arr[j]>sqrt(arr[i]))break;
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j])!=mp.end()){
                    long t=(long)mp[arr[j]]*mp[arr[i]/arr[j]];
                    if(arr[j]==(arr[i]/arr[j])){
                        mp[arr[i]]=(mp[arr[i]]+t)%mod;
                    }
                    else{
                        mp[arr[i]]=(mp[arr[i]]+ t * 2)%mod;
                       
                    }
                    cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
                }
            }
            
        }
        if(mp.size()>0)
        for(auto &t:mp)
        ans=(ans+t.second)%mod;
        return ans;
    }
};