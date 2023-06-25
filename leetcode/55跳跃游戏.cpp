class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1&&nums[0]==0) return true;
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++) {
            if(nums[i]>0&&dp[i-1]>=i) dp[i]=max(dp[i-1],i+nums[i]);
            else if(nums[i]==0) dp[i]=dp[i-1];
        }
        return dp[n-1]>=n-1?true:false;
    }
};
