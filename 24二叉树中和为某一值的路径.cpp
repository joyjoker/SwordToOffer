#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
/*********default*********/


	/*
	
	题目
		输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
		深度优先搜索。使用前序遍历，使用两个全局变量result和tmp，result来存放最终结果，tmp用来存放临时结果。
	
	每次遍历，我们先把root的值压入tmp，然后判断当前root是否同时满足：
	
	与给定数值相减为0；
	左子树为空；
	右子树为空。
	如果满足条件，就将tmp压入result中，否则，依次遍历左右子树。需要注意的是，遍历左右子树的时候，全局变量tmp是不清空的，直到到了根结点才请空tmp。
	*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	// 其实归根到底就是一个前序遍历 根左右  
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if(root == NULL) {
			return result; //代码的鲁棒性 
		}
		// 根 
		temp.push_back(root->val);
		if(expectNumber - root->val == 0 && root->left == NULL && root->right == NULL) {
			result.push_back(temp);
		} 
		
		// 左
		FindPath(root->left, expectNumber - root->val); 
		// 右 
		FindPath(root->right, expectNumber - root->val);
		
		temp.pop_back();
		return result;
    }
    
private:
	vector<vector<int>> result;
	vector<int> temp;
};

TreeNode *initBTree(int elements[], int size) {
	if(size < 1) {
		return NULL;
	}
	TreeNode **nodes = new TreeNode*[size];
 	for(int i = 0; i < size; i++) {
		if(elements[i] == 0) {
			nodes[i] = NULL;
		} else {
			nodes[i] = new TreeNode(elements[i]);
		}
	}
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(nodes[0]);
	int index = 1;
	TreeNode* node = NULL;
	while(index < size) {
		
		node = nodeQueue.front(); //作为根节点 
		nodeQueue.pop();
		
		nodeQueue.push(nodes[index++]);
		node->left = nodeQueue.back();
		
		nodeQueue.push(nodes[index++]);
		node->right = nodeQueue.back();
	}
	return nodes[0];
}
int main() {
	int elements[7] = {1, 3, 2, 4, 0, 5, 6};
	TreeNode *root = initBTree(elements, 7);
	Solution s;
	vector<vector<int>> result = s.FindPath(root, 8);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[0].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

