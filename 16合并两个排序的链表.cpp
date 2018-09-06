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
			输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
		*/ 

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):
		val(x), next(NULL){
		}
};

class Solution {
	public:
		//递归实现 非常简单 
		ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	        //先判断是否有空的链表
			if(pHead1 == NULL) {
				return pHead2;
			} else if(pHead2 == NULL) {
				return pHead1;
			}
			//也可以不开新链表 直接更改指针 把两个链表连起来 
			ListNode* newHead = NULL;
			if(pHead1->val > pHead2->val) {
				newHead = pHead2;
				newHead->next = Merge(pHead1, pHead2->next);
			} else {
				newHead = pHead1;
				newHead->next = Merge(pHead1->next, pHead2);
			}
			return newHead;
	    }
};
ListNode* CreateListNode(ListNode *head) {
	ListNode* p1, *p2;
	int i = 1;
	p1 = p2 = (ListNode*) malloc(sizeof(ListNode));
	cout << "please input the 1st node" << "it's address is p1_addr = " << p1 << "and input -1 to end" << endl;  
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
		cout << "please input the" << i << "st node" << "it's address is p" << i << "_addr = p" << i << "and input -1 to end" << endl; 
		cin >> p1->val;
		p1->next = NULL;
	}   
	free(p1);
	p1 = NULL;
	p2->next = NULL;
	return head;	
}

int main() {
	Solution s;
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = CreateListNode(head1);
	ListNode* head4 = CreateListNode(head2);
	ListNode* head5 = s.Merge(head3, head4);
	while(head5) {
		cout << head5->val << " ";
		head5 = head5->next;
	}	
	
	return 0;
}

