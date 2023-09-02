class Solution {
    bool good(int x, vector<int> &nums, int k) {
        int cnt = 1, s = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > x) return false;
            s += nums[i];
            if(s > x) { 
                cnt++;
                s = nums[i];
                if(cnt > k) return false;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int s = 0, e = 1e9, ans = INT_MAX;
        // for(int i : nums) e += i;
        
        while(s <= e) {
            int m = (s + e) / 2;
            if(good(m, nums, k)) e = m - 1, ans = min(ans, m);
            else s = m + 1;
        }
        return ans;
    }
};