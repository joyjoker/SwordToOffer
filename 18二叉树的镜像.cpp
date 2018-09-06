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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL){}
};

class Solution {
	public:
		void Mirror(TreeNode *pRoot) {
			if (pRoot == NULL) {
				return;
			}

	        TreeNode *pTmp;
	        pTmp = pRoot->left;
	        pRoot->left = pRoot->right;
	        pRoot->right = pTmp;
	        Mirror(pRoot->left);
	        Mirror(pRoot->right);
		}
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

void preOrder(TreeNode *pRoot) {
	if(pRoot) {
		cout << pRoot->val;
		preOrder(pRoot->left);
		preOrder(pRoot->right);
	}
}
int main() {
	int ele1[6] = {1, 2, 3};
	TreeNode *tree1 = initBTree(ele1, 3);
	preOrder(tree1);
	cout << endl;
	Solution s;
	s.Mirror(tree1);
	preOrder(tree1);
	return 0;
}

