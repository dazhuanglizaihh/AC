class Solution {
public:
    int dfs(vector<vector<int>>&land,int x,int y) {
        if(x<0||x>=land.size()||y<0||y>=land[0].size()||land[x][y])
            return 0;
        land[x][y]=1;
        int cnt=1;
        for(int i=x-1;i<=x+1;i++) {
            for(int j=y-1;j<=y+1;j++) {
                cnt+=dfs(land,i,j);
            }
        }
        return cnt;
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m=land.size(),n=land[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(land[i][j]==0) ans.push_back(dfs(land,i,j));
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
