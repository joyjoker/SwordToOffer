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
 
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
 
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
    	if(pHead == NULL) {
    		return NULL;
		}
    	// 最晚访问的不重复节点 
		ListNode* pPre = NULL;
		// 当前处理节点 
		ListNode* pCur = pHead;
		// 只想当前节点后的节点 
		ListNode* pNext = NULL;
		while(pCur) {
			// 如果当前节点和下一个节点相同
			if(pCur->next != NULL && pCur->val == pCur->next->val) {
				pNext = pCur->next;
				while(pNext->next != NULL && pNext->next->val == pNext->val) {
					pNext = pNext->next;
				} 
				// 当前节点和后面的节点相同 则全部剔除 
				if(pCur == pHead) {
					pHead = pNext->next;
				} else {
					pPre->next = pNext->next; 
				}
				pCur = pNext->next;
			} else {
			// 如果当前节点和下一个节点不同
				pPre = pCur;
				pCur = pCur->next; 
			}
			 
		}
		return pHead;
    }
};

int main() {

	return 0;
}

