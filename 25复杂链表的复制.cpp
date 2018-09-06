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
		输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
		注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
		*/

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReConnectNodes(pHead);
		
    }
    
    // 第一步 复制复杂指针的lable 和 next
    void CloneNodes(RandomListNode* pHead) {
    	RandomListNode* pNode = pHead;
    	while(pNode) {
    		RandomListNode* pCloned = new RandomListNode(0); // 复制 
    		pCloned->label = pNode->label;
			pCloned->next = pNode->next; 
			pCloned->random = NULL;
			
			pNode->next = pCloned;// 复制完将节点加入到 当前链表 
			pNode = pCloned->next;// 要复制的节点指针移动到已经复制的下一位 继续复制 
		}
	} 
	 
	// 第二步 处理复杂指针 random
	void ConnectSiblingNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		while(pNode) {
			RandomListNode* pCloned = pNode->next; // pCloned 指向复制的节点 
			if(pNode->random) {
				pCloned->random = pNode->random->next; 	// random 指针赋值 
			}
			pNode = pCloned->next;
		}
		
	} 
	
	// 第三步 拆分复杂链表
	RandomListNode* ReConnectNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		RandomListNode* pClonedHead = NULL; // 复制的链表的头 
		RandomListNode* PClonedNode = NULL; // 复制的链表的节点 
		 
		// 初始化  pClonedHead 和 PClonedNode
		if(pNode) {
			pClonedHead = PClonedNode = pNode->next;
			pNode->next = PClonedNode->next;
			pNode = pNode->next; // 此时 pNode 指向原链表第二个节点 
		} 
		
		while(pNode) {
			PClonedNode->next = pNode->next; 
			PClonedNode = PClonedNode->next;
			pNode->next = PClonedNode->next;
			pNode = pNode->next;
		}
		return pClonedHead;
	} 
    
};
int main() {

	return 0;
}

