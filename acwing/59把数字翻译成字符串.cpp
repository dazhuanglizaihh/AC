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
    string s="12258";    

    return 0;
}

class Solution {
public:
    int getTranslationCount(string s) {
        vector<int>dp(s.size()+1,0);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=s.size();i++) {
            string t=s.substr(i-2,2);
            if(t.compare("10")>=0&&t.compare("25")<=0) {
                dp[i]=dp[i-1]+dp[i-2];
            } else {
                dp[i]=dp[i-1];
            }
        }
        return dp[s.size()];
    }
};
