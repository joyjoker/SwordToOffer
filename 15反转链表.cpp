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
// 题目描述: 输入一个链表，反转链表后，输出新链表的表头。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	//使用一个栈
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == NULL) {
			return NULL;
		}
		stack<ListNode*> s;
		ListNode* p = pHead;
		while(p->next) {
			s.push(p);
			p = p->next;
		} 
		ListNode* head = p;
		while(!s.empty()) {
			p->next = s.top();//更改指针指向 实现反转 
			p = p->next;
			s.pop();
		}
		p->next = NULL;//必须要 
		return head;
    }
    //使用三个指针
	ListNode* ReverseList2(ListNode* pHead) {
		if(pHead == NULL) {
			return NULL; 
		}
		
		ListNode* pNode = pHead;// 当前节点 第一个指针 
		ListNode* pReverseHead = NULL;// 新链表头指针 
		ListNode* pPre = NULL;  // 当前节点前一个节点 因为当前节点是头结点 前一个节点为空 第二个指针 
		while(pNode) { //当前节点不为空 
			ListNode* pNext = pNode->next; //当前节点下一个节点 第三个指针 
			
			if(pNext == NULL) { //pNext为空表示遍历到尾节点 
				pReverseHead = pNode;
			} 
			
			pNode->next = pPre; //指针反转 
			pPre = pNode;  // 同时向后移动一位 
			pNode = pNext;
		} 
		return pReverseHead;
	}
	//递归实现
	ListNode* ReverseList3(ListNode* pHead)  {
		//如果链表为空或者链表中只有一个元素
        if(pHead==NULL||pHead->next==NULL) {
        	return pHead;
		} 
		//先反转后面的链表，走到链表的末端结点
		ListNode* pReverseHead = ReverseList3(pHead->next);
		//再将当前节点设置为后面节点的后续节点
		pHead->next->next = pHead;
		pHead->next = NULL;
		
		return pReverseHead;
	}
};

ListNode* CreateListNode(ListNode *head) {
	ListNode* p1, *p2;
	int i = 1;
	p1 = p2 = (ListNode*) malloc(sizeof(ListNode));
	cout << "please input the 1st node" << "it's address is p1_addr = " << p1 << " and input -1 to end." << endl;  
	cin >> p1->val;
	p1->next = NULL;
	while(p1->val != -1) {
		if(head == NULL) {
			head = p1;
		} else {
			p2->next = p1;
			p2 = p2->next;
		}
		p1 = (ListNode*)malloc(sizeof(ListNode));
		i++;
		cout << "please input the " << i << "st node" << "it's address is p" << i << "_addr = p" << i << p1 << " and input -1 to end." << endl; 
		cin >> p1->val;
		p1->next = NULL;
	}   
	free(p1);
	p1 = NULL;
	p2->next = NULL;
	return head;	
}

int main() {
	//测试 
	ListNode *head = NULL;
	ListNode* head1 = CreateListNode(head);
	Solution s;
	ListNode* head2 = s.ReverseList3(head1); //改变1 2 3 测试三种情况 
	while(head2) {
		cout << head2->val << " ";
		head2 = head2->next;
	}
	
	return 0;
}

