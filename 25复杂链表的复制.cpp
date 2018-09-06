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
		����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
		ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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
    
    // ��һ�� ���Ƹ���ָ���lable �� next
    void CloneNodes(RandomListNode* pHead) {
    	RandomListNode* pNode = pHead;
    	while(pNode) {
    		RandomListNode* pCloned = new RandomListNode(0); // ���� 
    		pCloned->label = pNode->label;
			pCloned->next = pNode->next; 
			pCloned->random = NULL;
			
			pNode->next = pCloned;// �����꽫�ڵ���뵽 ��ǰ���� 
			pNode = pCloned->next;// Ҫ���ƵĽڵ�ָ���ƶ����Ѿ����Ƶ���һλ �������� 
		}
	} 
	 
	// �ڶ��� ������ָ�� random
	void ConnectSiblingNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		while(pNode) {
			RandomListNode* pCloned = pNode->next; // pCloned ָ���ƵĽڵ� 
			if(pNode->random) {
				pCloned->random = pNode->random->next; 	// random ָ�븳ֵ 
			}
			pNode = pCloned->next;
		}
		
	} 
	
	// ������ ��ָ�������
	RandomListNode* ReConnectNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		RandomListNode* pClonedHead = NULL; // ���Ƶ������ͷ 
		RandomListNode* PClonedNode = NULL; // ���Ƶ�����Ľڵ� 
		 
		// ��ʼ��  pClonedHead �� PClonedNode
		if(pNode) {
			pClonedHead = PClonedNode = pNode->next;
			pNode->next = PClonedNode->next;
			pNode = pNode->next; // ��ʱ pNode ָ��ԭ����ڶ����ڵ� 
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

