class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=INT_MIN,ans0=INT_MIN;
        bool flag1=false;
        for(int i=0;i<strs.size();i++) {
            for(int j=0;j<strs[i].size();j++) {
                for(int k=97;k<=122;k++) {
                    if(strs[i][j]==k) flag1=true;
                }
            }
            if(flag1==true) {int m=strs[i].size(); ans=max(ans,m); flag1=false; }
            else if(flag1==false) { 
                ans0=0;
                for(int j=strs[i].size()-1,mul=0;j>=0;j--,mul++) {
                    int num=strs[i][j]-48;
                    int muls=pow(10,mul);
                    ans0+=num*muls;
                }
                ans=max(ans,ans0);
            }
        }
        return ans;
    }
};
