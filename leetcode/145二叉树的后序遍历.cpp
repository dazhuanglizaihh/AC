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

vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    stack<TreeNode*> sta;
	map<TreeNode*,TreeNode*> umap;
    sta.push(root);
	if(root==nullptr) return {};
    while(!sta.empty()) 
	{
        TreeNode*node=sta.top();
        if(node->left!=nullptr) 
		{
            TreeNode* left_node=node->left;
			sta.push(left_node);
			umap[left_node]=node;
			continue;
        }
		else if(node->left==nullptr)
		{
			if(node->right!=nullptr)
			{
				TreeNode* right_node=node->right;
				sta.push(right_node);
				umap[right_node]=node;
				continue;
			}
			else if(node->right==nullptr)
			{
				ans.push_back(sta.top()->val); 
				//当前节点的父节点
				TreeNode* f_node=umap[sta.top()];
				if(f_node!=nullptr&&f_node->left!=nullptr&&f_node->left==sta.top()) f_node->left=nullptr;
				else if(f_node!=nullptr&&f_node->right!=nullptr&&f_node->right==sta.top()) f_node->right=nullptr;
				sta.pop();
			}
		}
	}
	return ans;
}
