#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int kthSmallest(vector<vector<int>>&, int);

int main()
{
	vector<vector<int>> mat;
	for(int i=0;i<3;i++)
	{
		vector<int> row;
		for(int j=0;j<3;j++)
		{
			int val;
			cin >> val; 
			row.push_back(val);
		}
		mat.push_back(row);
	}
	int k;
	cin >> k;


	int ans =kthSmallest(mat,k);
	cout << ans;
	return 0;
}

int kthSmallest(vector<vector<int>> &mat, int k)
{
	vector<int> ans;
	queue<int> que;
	if (mat.size() == 1)
		return mat[0][k - 1];
	for (int i = 0; i < mat[0].size(); i++)
		que.push(mat[0][i]);

	for (int i = 1; i < mat.size();)
	{
		int top = que.front();
		que.pop();
		for (int j = 0; j < mat[i].size(); j++)
		{
			int sum=top+mat[i][j];
			ans.push_back(sum);
		}
		if (que.empty())
		{
			i++;
			sort(ans.begin(),ans.end());
			int len = ans.size()<k?ans.size():k;
			for (int i = 0; i < len; i++) 
				que.push(ans[i]);
			ans.clear();
		}
	}
	int res=-1;
	for(int i=0;i<k-1;i++)
		que.pop();
	res=que.front();
	return res;
}