#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};
vector<int> postorderTraversal(TreeNode*);
TreeNode* sufficientSubset(TreeNode*,int);
int main()
{
	TreeNode* node0=new TreeNode(1);
	TreeNode* node2=new TreeNode(2);
	TreeNode* node3=new TreeNode(3);
	node0->right=node2; node0->left=nullptr;
	node2->left=node3; node2->right=nullptr;
	vector<int> ans=postorderTraversal(node0);
	for(auto a:ans) cout << a << endl;
	return 0;
}


TreeNode* sufficientSubset(TreeNode* root,int limit)
{

}

