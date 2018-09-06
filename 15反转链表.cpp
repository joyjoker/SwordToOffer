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
// ��Ŀ����: ����һ��������ת��������������ı�ͷ��
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	//ʹ��һ��ջ
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
			p->next = s.top();//����ָ��ָ�� ʵ�ַ�ת 
			p = p->next;
			s.pop();
		}
		p->next = NULL;//����Ҫ 
		return head;
    }
    //ʹ������ָ��
	ListNode* ReverseList2(ListNode* pHead) {
		if(pHead == NULL) {
			return NULL; 
		}
		
		ListNode* pNode = pHead;// ��ǰ�ڵ� ��һ��ָ�� 
		ListNode* pReverseHead = NULL;// ������ͷָ�� 
		ListNode* pPre = NULL;  // ��ǰ�ڵ�ǰһ���ڵ� ��Ϊ��ǰ�ڵ���ͷ��� ǰһ���ڵ�Ϊ�� �ڶ���ָ�� 
		while(pNode) { //��ǰ�ڵ㲻Ϊ�� 
			ListNode* pNext = pNode->next; //��ǰ�ڵ���һ���ڵ� ������ָ�� 
			
			if(pNext == NULL) { //pNextΪ�ձ�ʾ������β�ڵ� 
				pReverseHead = pNode;
			} 
			
			pNode->next = pPre; //ָ�뷴ת 
			pPre = pNode;  // ͬʱ����ƶ�һλ 
			pNode = pNext;
		} 
		return pReverseHead;
	}
	//�ݹ�ʵ��
	ListNode* ReverseList3(ListNode* pHead)  {
		//�������Ϊ�ջ���������ֻ��һ��Ԫ��
        if(pHead==NULL||pHead->next==NULL) {
        	return pHead;
		} 
		//�ȷ�ת����������ߵ������ĩ�˽��
		ListNode* pReverseHead = ReverseList3(pHead->next);
		//�ٽ���ǰ�ڵ�����Ϊ����ڵ�ĺ����ڵ�
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
	//���� 
	ListNode *head = NULL;
	ListNode* head1 = CreateListNode(head);
	Solution s;
	ListNode* head2 = s.ReverseList3(head1); //�ı�1 2 3 ����������� 
	while(head2) {
		cout << head2->val << " ";
		head2 = head2->next;
	}
	
	return 0;
}

