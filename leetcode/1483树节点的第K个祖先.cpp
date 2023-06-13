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
    int a=log2(50000);
    cout<<a;
	return 0;
}

class TreeAncestor {
public:
    vector<vector<int>> ancestor;
    int Log=log2(50000)+1;
    // int Log=16;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestor=vector<vector<int>>(n,vector<int>(Log,-1));
        for(int i=0;i<n;i++)
            ancestor[i][0]=parent[i];
        for(int j=1;j<Log;j++)
            for(int i=0;i<n;i++)
                if(ancestor[i][j-1]!=-1) 
                    ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<Log;i++)
        {
            if(k>>i&1) 
            {
                node=ancestor[node][i];
                if(node==-1) return -1;
            }
        }
        return node;
    }
};



