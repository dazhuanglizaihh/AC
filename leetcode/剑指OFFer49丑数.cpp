#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
using namespace std;


int nthUglyNumber(int);

int main()
{
	cout << nthUglyNumber(10);
	return 0;
}

/**
 * 丑数:只包含质因子2、3、5的数
 * 1是丑数
 * 丑数求法： 1*2 1*3 1*5-> mix，得下一个丑数
*/
int nthUglyNumber(int n) {
	//a,b,c：index
	int a=0,b=0,c=0;
	vector<int> ans(n,0);
	ans[0]=1;
	for(int i=1;i<n;i++)
	{
		int an=ans[a]*2, bn=ans[b]*3,cn=ans[c]*5;
		ans[i]=min(an,min(bn,cn));
		if(ans[i]==an) a++;
		if(ans[i]==bn) b++;
		if(ans[i]==cn) c++;
	}
	return ans[n-1];
}