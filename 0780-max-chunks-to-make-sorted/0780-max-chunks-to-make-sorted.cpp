class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxtillnow=-1;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(i>maxtillnow){
                ans++;
            }
            maxtillnow=max(maxtillnow,arr[i]);
        }
        return ans;
    }
};