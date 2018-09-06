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
����Ҳ�������ðѳ��������ͷ��������������������ͬ��������ͬʱ����Ҳ���ҵ�������㡣��ʱ��ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�ΪO(MAX(m,n))��
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
}; 
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // �����һ���� �򷵻ؿ�
		if(pHead1 == NULL || pHead2 == NULL) {
			return NULL;
		} 
		int length1 = GetLenth(pHead1);
		int length2 = GetLenth(pHead2);
		// Ĭ�� pHead1 �ϳ� ������� �ٸ�
		ListNode* pHeadLong = pHead1;
		ListNode* pHeadShort = pHead2; 
		int lengthDiff = length1 - length2;
		if(length1 < length2) {
			pHeadLong = pHead2;
			pHeadShort = pHead1;
			lengthDiff = length2 - length1;
		}
		
		// ȥ������ǰ�沿�� ʹ����һ���� 
		while(lengthDiff) {
			pHeadLong = pHeadLong->next;
			lengthDiff--;
		} 
		while(pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort) {
			pHeadLong = pHeadLong->next;
			pHeadShort = pHeadShort->next;
		}
		return pHeadLong;
    }
private:
	// ��������� 
	int GetLenth(ListNode* pHead) {
		int length = 0;
		while(pHead) {
			pHead = pHead->next;
			length++;
		}
		return length;
	}
};


int main() {

	return 0;
}

