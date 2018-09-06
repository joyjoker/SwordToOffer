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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
		if(pHead == NULL) {
			return NULL;
		}
		ListNode *meetNode = MeetNode(pHead);
		if(meetNode == NULL) {
			return NULL;
		}
		// 找到环中节点数目
		int loopNodes = 1;
		ListNode* pNode = meetNode;
		while(pNode->next != meetNode) {
			pNode = pNode->next;
			loopNodes++;
		}
		pNode = pHead;
		for(int i = loopNodes; i > 0; i--) {
			pNode = pNode->next;
		}
		ListNode* pNode1 = pHead;
		while(pNode != pNode1) {
			pNode = pNode->next;
			pNode1 = pNode1->next;
		}
		return pNode;
    }
private:
	// 使用快慢指针  找到任意一个环中节点 
 	ListNode* MeetNode(ListNode * pHead) {
 		ListNode *pSlow = pHead->next;
		if(pSlow == NULL) {
			return NULL;
		}  
		ListNode *pFast = pSlow->next;
		if(pFast != NULL) {
			while(pFast->next) {
				if(pFast == pSlow) {
					return pFast;
				}
				pFast = pFast->next;
				pSlow = pSlow->next;
				if(pFast->next) {
					pFast = pFast->next;
				}
			}
		}
		return NULL;
	 }
};


int main() {
	
	return 0;
}

