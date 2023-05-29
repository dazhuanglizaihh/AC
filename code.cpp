#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int kthSmallest(vector<vector<int>>&, int);
vector<double> sampleStats(vector<int>&);
int main()
{
	vector<int> count={0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<double> a=sampleStats(count);
	for (auto& val: a) cout << val << endl;
	return 0;
}

vector<double> sampleStats(vector<int>& count) 
{
	double minimum,maximum,mean,median,mode;
	int vaild_step=0,max_val=-1;
	double total;

	bool odevity=false;
	map<double,double> umap;
	for(int i=0;i<count.size();i++) 
		if(count[i]!=0) 
		{
			umap[i]=count[i];
			total+=count[i]*i;
			vaild_step++;
			int d=max_val;
			max_val=max(count[i],max_val);
			if(d!=max_val)
			{
				mode=count[i];
			}
		}
	//奇fasle偶true
	if(vaild_step%2==0) odevity=true;
	else if(vaild_step%2!=0) odevity=false;
	auto ite=umap.begin();
	minimum=ite->first;
	ite=umap.end(); ite--;
	maximum=ite->first;
	mean=total/vaild_step;
	int vaild_step_median=vaild_step/2;
	int step=0;
	auto a=umap.begin();
	for( ;a!=umap.end();a++)
	{
		step++;
		if(step==vaild_step_median) break;
	}
	if(odevity==true) 
	{
		median=a->first; a++;
		median+=a->first;
	}
	else if(odevity==false) 
	{
		median=a->first;
	}
	return {minimum,maximum,mean,median,mode};
}