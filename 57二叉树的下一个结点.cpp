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


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == NULL) {
        	return NULL;
		} 
		TreeLinkNode* pNext = NULL;
		// 当前结点有右子树，那么它的下一个结点就是它的右子树中最左子结点
		if(pNode->right) {
			TreeLinkNode* pRight = pNode->right;
			while(pRight->left) {
				pRight = pRight->left;
			}
			pNext = pRight;	
		// 当前节点无右子树 如果当前节点是父节点左子节点 则找到父节点即可
		//  如果当前节点是父节点左子节点 则找到父节点是下个父节点左子节点即可
		} else if(pNode->next) {
			TreeLinkNode* pCurrent = pNode;
			TreeLinkNode* pParent = pNode->next;

			while(pParent != NULL && pParent->right == pCurrent) {
				pCurrent = pParent;
				pParent = pCurrent->next;
			}
			pNext = pParent;
		} 
		return pNext;
    }
};

int main() {

	return 0;
}

