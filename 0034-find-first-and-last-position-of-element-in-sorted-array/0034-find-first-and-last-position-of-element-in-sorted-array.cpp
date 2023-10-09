class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={INT_MAX,INT_MIN};
        int l=nums.size()-1;
        int s=0;
        while(l>=s){
            int mid=(l+s)/2;
            cout<<mid<<endl;
            if(nums[mid]<=target){

                if(ans[1]<mid && nums[mid]==target){
                    cout<<mid<<" 1"<<endl;
                    ans[1]=mid;
                }
                s=mid+1;
            }
            else{
                l=mid-1;
            }
            
        }
        l=nums.size()-1;
        s=0;
        while(l>=s){
            int mid=(s+l)/2;
            if(nums[mid]>=target){
                if(ans[0]>mid && nums[mid]==target){
                    ans[0]=mid;

                }
                l=mid-1;
            }
                else{
                    s=mid+1;
                }
        }
        if(ans[0]==INT_MAX){
            return{-1,-1};
        }
        return ans;
    }
};