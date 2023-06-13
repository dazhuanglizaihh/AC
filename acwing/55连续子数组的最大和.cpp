#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};
    return 0;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int res=nums[0];
        ans[0]=nums[0];
        for(int i=0;i<nums.size();i++) {
            if(ans[i-1]<0) {
                ans[i]=nums[i];
            } else {
                ans[i]=ans[i-1]+nums[i];
            }
            res=max(res,ans[i]);
        }
        return res;
    }
};
