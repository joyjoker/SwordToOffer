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
		val(x), left(NULL), right(NULL){
		}
};
// 打印一个节点时 如果它有子节点 则加入队列 所谓层序遍历 
class Solution {
	public:
		vector<int> PrintFromTopToBottom(TreeNode *root) {
			vector<int> result;
			if(root == NULL) {
				return result;
			}
			queue<TreeNode*> queue;
			TreeNode *node; //当前节点 
			queue.push(root);
			while(!queue.empty()) {
				node = queue.front();
				result.push_back(node->val);
				if(node->left != NULL) {
					queue.push(node->left);	
				} 
				if(node->right != NULL) {
					queue.push(node->right);
				}
				queue.pop();
			} 
			return result;
		}
};

TreeNode *initBTree(int elements[], int size) {
	if(size < 1) {
		return NULL;
	}
	queue<TreeNode*> queue;
	TreeNode **nodes = new TreeNode*[size];
	for(int i = 0; i < size; i++) {
		if(elements[i] == 0) {
			nodes[i] = NULL;
		} else {
			nodes[i] = new TreeNode(elements[i]);
		}
	}
	queue.push(nodes[0]);
	int index = 1;
	TreeNode *node = NULL;
	while(index < size) {
		node = queue.front();
		queue.pop();
		queue.push(nodes[index++]);
		node->left = queue.back();
		queue.push(nodes[index++]);
		node->right = queue.back();
	}
	return nodes[0];
}
int main() {
	int element[7] = {8, 6, 10, 5, 7, 9, 11};
	TreeNode *root = initBTree(element, 7);
	Solution s;
	vector<int> resoult;
	resoult = s.PrintFromTopToBottom(root);
	for(int v : resoult) {
		cout << v << " ";
	}
	return 0;
}

