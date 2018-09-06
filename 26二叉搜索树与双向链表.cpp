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
		输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
		*/
		
		/*
		根据二叉搜索树的特点：左结点的值<根结点的值<右结点的值，我们不难发现，使用二叉树的中序遍历出来的数据的数序，就是排序的顺序。
		因此，首先，确定了二叉搜索树的遍历方法。
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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        //pLastNodeInList 用于记录双向链表尾指针
		TreeNode *pLastNodeInList = NULL;
		
		//开始转换
		ConvertNode(pRootOfTree, &pLastNodeInList);
		
		//pLastNodeInList 指向双向链表尾节点 我们需要返回头结点
		TreeNode *pHeadNodeInList = pLastNodeInList;
		while(pHeadNodeInList && pHeadNodeInList->left) {
			pHeadNodeInList = pHeadNodeInList->left;
		}
		return pHeadNodeInList;
    }									
    void ConvertNode(TreeNode *pNode, TreeNode **pLastNodeInList) {
    	if(pNode == NULL) {
    		return; //此树没有节点 
		}
		TreeNode *pCurrent = pNode; // 当前子树根节点
		
		// 中序遍历 左 根 右 
		
		// 1.递归左子树
		if(pCurrent->left != NULL) {
			ConvertNode(pCurrent->left, pLastNodeInList);
		} 
		
		// 2.当前树根节点左指针 应该指向子树 链表尾节点 右指针还没用到 
		pCurrent->left = *pLastNodeInList;
		// 3.双向链表右指针 指向当前根节点
		if(*pLastNodeInList != NULL) {
			(*pLastNodeInList)->right = pCurrent;
		} 
		
		// 4.更新双向链表尾节点 
		*pLastNodeInList = pCurrent; 
		
		// 5.遍历右子树 
		if(pCurrent->right != NULL) {
			ConvertNode(pCurrent->right, pLastNodeInList);
		}	
	}
};


int main() {

	return 0;
}

