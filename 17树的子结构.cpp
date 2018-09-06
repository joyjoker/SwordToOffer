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
		题目描述
		输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		bool result = false;
		if(pRoot1 != NULL && pRoot2 != NULL) {
			if(pRoot1->val == pRoot2->val) {
				result = DoesTree1HasTree2(pRoot1, pRoot2);
			}
			if(!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if(!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
    }
private:
	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
		if(pRoot2 == NULL) {
			return true;
		}
		if(pRoot1 == NULL) {
			return false;
		}
		if(pRoot1->val != pRoot2->val) {
			return false;
		}
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};

TreeNode *initBTree(int elements[], int size) {
	if(size < 1) {
		return NULL;//小于1 建不成树 没啥说的 
	}
	//动态申请大小为size的指针数组
	TreeNode **nodes = new TreeNode*[size];
	//将数组中的int类型转换成TreeNode 节点
	for(int i = 0; i < size; i++) {
		if(elements[i] == 0) {
			nodes[i] = NULL;
		} else {
			nodes[i] = new TreeNode(elements[i]);
		}
	} 
	
	//使用一个队列暂存节点
	queue<TreeNode*> nodeQueue;
	//nodes[0]就是这棵树的根节点 
	nodeQueue.push(nodes[0]);
	int index = 1; // 0号已经进栈了
	TreeNode *node;
	/*
		 解释下:
		 	首先上面已经进栈了根节点 赋值给node 
			将根节点出栈 然后再进栈的 就是左子树根节点 赋值给 node->left
	*/
	while(index < size) {
		node = nodeQueue.front();
		nodeQueue.pop();
		nodeQueue.push(nodes[index++]);
		node->left = nodeQueue.back();
		nodeQueue.push(nodes[index++]);
		node->right = nodeQueue.back();
	} 
	                         
	return nodes[0];
} 

int main() {
	int ele1[6] = {1, 3, 4, 5, 6, 7};
	int ele2[3] = {3, 5, 3};
	TreeNode *tree1 = initBTree(ele1, 6);
	TreeNode *tree2 = initBTree(ele2, 3);
	Solution s;
	bool b = s.HasSubtree(tree1, tree2);
	cout << b << endl;
	return 0;
}

