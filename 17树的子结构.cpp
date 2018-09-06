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
		��Ŀ����
		�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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
		return NULL;//С��1 �������� ûɶ˵�� 
	}
	//��̬�����СΪsize��ָ������
	TreeNode **nodes = new TreeNode*[size];
	//�������е�int����ת����TreeNode �ڵ�
	for(int i = 0; i < size; i++) {
		if(elements[i] == 0) {
			nodes[i] = NULL;
		} else {
			nodes[i] = new TreeNode(elements[i]);
		}
	} 
	
	//ʹ��һ�������ݴ�ڵ�
	queue<TreeNode*> nodeQueue;
	//nodes[0]����������ĸ��ڵ� 
	nodeQueue.push(nodes[0]);
	int index = 1; // 0���Ѿ���ջ��
	TreeNode *node;
	/*
		 ������:
		 	���������Ѿ���ջ�˸��ڵ� ��ֵ��node 
			�����ڵ��ջ Ȼ���ٽ�ջ�� �������������ڵ� ��ֵ�� node->left
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

