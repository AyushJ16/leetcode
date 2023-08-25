class Solution {
private:
    int solve(int n, vector<int>&nums, vector<int>&dp){
        if(n < 0)return 0;
        if(dp[n] != -1)return dp[n];
        int take = 0, notTake =0;
        notTake = solve(n-1, nums, dp);
        int i = n, sum =0;
        while(i >= 0 && nums[i] == nums[n]){
            sum += nums[i];
            i--;
        }
        while(i >= 0 && nums[i] == nums[n] - 1){
            i--;
        }
        take = sum + solve(i, nums, dp);
        return dp[n] = max(take, notTake);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        // priority_queue<pair<int,int>>pq;
        // unordered_map<int,int> freq;
        // unordered_set<int>del;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        // }
        // for(auto &nums:freq){
        //     pq.push({nums.first*nums.second,nums.first});
        // }
        // int del1=0,del2=0;
        // int ans=0;
        // while(!pq.empty()){
        //     del1=0,del2=0;
        //     auto p=pq.top();
        //     pq.pop();
        //     int num=p.second;
        //     cout<<num<<" "<<p.first<<endl;
        //     if(del.find(num)!=del.end()){
        //         continue;
        //     }
        //     int val=p.first;
        //     if(del.find(num-1)==del.end())
        //     del1=freq[num-1]*(num-1);
        //     if(del.find(num+1)==del.end())
        //     del2=freq[num+1]*(num+1);
        //     if(val<(del1+del2)){
        //         val=del1+del2;
        //         del.insert(num+2);
        //         del.insert(num-2);
        //     }
        //     cout<<del1<<" "<<del2<<endl;
        //     cout<<num<<" "<<p.first<<" "<<val<<endl;
        //     ans+=val;
        //     del.insert(num);
        //     del.insert(num+1);
        //     del.insert(num-1);
        // }
        // return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>dp(n+1, -1);
        return solve(n-1, nums, dp);
    }
    
};