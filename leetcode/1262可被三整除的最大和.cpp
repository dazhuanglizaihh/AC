class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size(),dp[n+1][3];
        dp[0][0]=0;dp[0][1]=INT_MIN;dp[0][2]=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<3;j++) {
                dp[i+1][j]=max(dp[i][j],dp[i][(j+nums[i])%3]+nums[i]);
            }
        }
        return dp[n][0];
    }
};
