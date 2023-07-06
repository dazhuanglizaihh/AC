class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int flag=nums[0].size(),ans=0,res=0;
        for(int i=0;i<nums[0].size();i++) {
            for(int j=0,max_num=INT_MIN;j<nums.size();j++) {
                int row=0,col=0;
                for(int k=0,ans0=INT_MIN;k<nums[j].size();k++) {
                    if(nums[j][k]>ans0) {
                        ans0=nums[j][k];
                        row=j; col=k;
                    }
                }
                max_num=max(max_num,nums[row][col]);
                nums[row][col]=-1;
                ans=max_num;
            }
            res+=ans;
        }
        return res;
    }
};
