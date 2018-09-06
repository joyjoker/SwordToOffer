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
		����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
		*/
		
		/*
		���ݶ������������ص㣺�����ֵ<������ֵ<�ҽ���ֵ�����ǲ��ѷ��֣�ʹ�ö�����������������������ݵ����򣬾��������˳��
		��ˣ����ȣ�ȷ���˶����������ı���������
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
        //pLastNodeInList ���ڼ�¼˫������βָ��
		TreeNode *pLastNodeInList = NULL;
		
		//��ʼת��
		ConvertNode(pRootOfTree, &pLastNodeInList);
		
		//pLastNodeInList ָ��˫������β�ڵ� ������Ҫ����ͷ���
		TreeNode *pHeadNodeInList = pLastNodeInList;
		while(pHeadNodeInList && pHeadNodeInList->left) {
			pHeadNodeInList = pHeadNodeInList->left;
		}
		return pHeadNodeInList;
    }									
    void ConvertNode(TreeNode *pNode, TreeNode **pLastNodeInList) {
    	if(pNode == NULL) {
    		return; //����û�нڵ� 
		}
		TreeNode *pCurrent = pNode; // ��ǰ�������ڵ�
		
		// ������� �� �� �� 
		
		// 1.�ݹ�������
		if(pCurrent->left != NULL) {
			ConvertNode(pCurrent->left, pLastNodeInList);
		} 
		
		// 2.��ǰ�����ڵ���ָ�� Ӧ��ָ������ ����β�ڵ� ��ָ�뻹û�õ� 
		pCurrent->left = *pLastNodeInList;
		// 3.˫��������ָ�� ָ��ǰ���ڵ�
		if(*pLastNodeInList != NULL) {
			(*pLastNodeInList)->right = pCurrent;
		} 
		
		// 4.����˫������β�ڵ� 
		*pLastNodeInList = pCurrent; 
		
		// 5.���������� 
		if(pCurrent->right != NULL) {
			ConvertNode(pCurrent->right, pLastNodeInList);
		}	
	}
};


int main() {

	return 0;
}

