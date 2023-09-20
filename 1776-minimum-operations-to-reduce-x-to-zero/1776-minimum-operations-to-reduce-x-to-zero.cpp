class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int>pre1,pre2;
        int n=nums.size();
        int ans=INT_MAX;
        if(nums.size()==1){
            return nums[0]==x?1:-1;
        }
        pre1.push_back(nums[0]);
        if(pre1[0]==x)return 1;
        pre2.push_back(nums[n-1]);
        if(pre2[0]==x)return 1;
        for(int i=1;i<n;i++){
            if(pre1[i-1]+nums[i]<=x){
                pre1.push_back(pre1[i-1]+nums[i]);
            }
            else{
                break;
            }
            if(pre1[i]==x)ans=min(ans,i+1);
            if(i==n-1 && pre1[n-1]<x){
                return -1;
            }
        }
        int pos=1;
        for(int i=n-2;i>=0;i--){
            if(pre2[pos-1]+nums[i]<=x){
                pre2.push_back(pre2[pos-1]+nums[i]);
            }
            else{
                break;
            }
            if(pre2[pos]==x)ans=min(ans,pos+1);
            pos++;

        }
        cout<<pre1.size()<<" "<<pre2.size()<<endl;
        int i=pre1.size()-1,j=0;
        int temp=i+1;
        while(i>=0 && j<pre2.size()){
            if(pre1[i]+pre2[j]==x)ans=min(ans,i+1+j+1);
            if(pre1[i]+pre2[j]<x){
                j++;
                // continue;
            }
            else{
                i--;
            }
        }
        return ans==INT_MAX?-1:ans;

    }
};