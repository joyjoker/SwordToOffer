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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == NULL || k == 0) {
    		return NULL;
		}
		ListNode* pAhead = pListHead;
		ListNode* pBehind = pListHead;
		for(int i = 0; i < k - 1; i++) {
			if(pAhead->next != NULL) {
				pAhead = pAhead->next;
			} else {
				return NULL;
			}
		}
		while(pAhead->next != NULL) {
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
    }
	ListNode* CreateListNode(ListNode *head);
};
//创建一个单链表 
ListNode* Solution::CreateListNode(ListNode *head) {
	ListNode* p1, *p2;
	int i = 1;
	p1 = p2 = (ListNode*)malloc(sizeof(ListNode));
	cout << "please input the 1st node" << "it's address is p1_addr = " << p1 << "and input -1 to end." << endl;  
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
		cout << "please input the" << i << "st node" << "it's address is p" << i << "_addr = p" << i << p1 << "and input -1 to end." << endl; 
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
	ListNode* head = NULL;
	ListNode *head1 = s.CreateListNode(head); 
	ListNode *head2 = head1;
	while(head1 != NULL) {
		cout << head1->val << " ";
		head1 = head1->next;
	}
	
	cout << endl << "the result is:" << endl << s.FindKthToTail(head2, 4)->val;
	return 0;
}

