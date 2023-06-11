#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
using namespace std;

int tilingRectangle(int, int);
int longestSemiRepetitiveSubstring(string);
int main()
{
	int a=longestSemiRepetitiveSubstring("52233");
	cout<<a;
	return 0;
}
/**
 * 滑动窗口
 * 维护一个窗口，当窗口中出现一对相同字符时，则记录当前窗口长度，并将窗口滑动远离当前子字符串
 * 窗口在遇见第一对相同值时会继续往后滑动，直到再次遇见第二对相同的值。当遇见第二对时，左边界收缩
*/
int longestSemiRepetitiveSubstring(string s)
{
	int left=0,right=1,ans=1,same=0;
	for(;right<s.size();right++)
	{
		if(s[right]==s[right-1]&&++same>1)
		{
			for(++left;s[left]!=s[left-1];left++);
			same=1;
		} 
		ans=max(ans,right-left+1);
	}
	return ans;
}

