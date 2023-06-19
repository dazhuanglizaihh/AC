#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <cmath>
using namespace std;

string longestPalindrome(string);

int main()
{   
    string s="babad";
    longestPalindrome(s);
    return 0;
}

string longestPalindrome(string s) 
{
    int n=s.size(),maxlen=1,begin=0;
    if(n==1) return s;
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int len=2;len<=n;len++) 
    {
        for(int i=0,j=0;i<n;i++)
        {
            j=i+len-1;
            if(j>=n) break;
            if(s[i]!=s[j]) dp[i][j]=false;
            else 
            {
                if(len<4) dp[i][j]=true;
                else dp[i][j]=dp[i+1][j-1];
            }
            if(dp[i][j]==true&&len>maxlen) 
            {
                maxlen=len;
                begin=i;
            }
        }
    }
    return s.substr(begin,maxlen);
}

