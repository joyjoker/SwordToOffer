#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

//����ڵ㶨��
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL) {
		}		
};

//�����β��ͷ����ڵ�ֵ
class Solution {
	public:
		//����1��ͨ��stack ���container��ʵ�ַ�ת����
		vector<int> printListFromTailToHead(struct ListNode *head) {
			vector<int> result;
			if(head == NULL) {
				return result;
			}	
			stack<ListNode *> reverse;
			ListNode *node = head;
			while(node != NULL) {
				reverse.push(node);
				node = node->next;
			}
			while(!reverse.empty()) {
				node = reverse.top();
				result.push_back(node->val);
				reverse.pop();
			}
			return result;
		} 
		
		//����2��ԭ�ط�ת��������������container
 	    //���ϵ�ʹ����һ���ڵ㡱ָ��ǰһ�����ڵ�
    	vector<int> printListFromTailToHead2(struct ListNode* head) { 
            vector<int> vec; 
            ListNode *buf = head; 
            ListNode *pre = buf; 
            if(head == NULL) 
                return vec; 
            while(head->next != NULL){ 
                buf = head->next; 
                head->next = buf->next; 
                buf->next = pre; 
                pre = buf; 
            } 
            while(buf){ 
                vec.push_back(buf->val); 
                buf = buf->next; 
            } 
            return vec; 
        }
}; 

//��ʼ������ 
struct ListNode* CreateListNode(struct ListNode *head) {
	struct ListNode *p1, *p2;
	int i = 1;
	p1 = p2 = (ListNode *) malloc(sizeof(ListNode));
	cout << "Please input the 1st node, it's address is p1_addr = " << p1 << endl;
 	cout << "And input -1 to quit." << endl;
 	cin >> (p1->val);
 	p1->next = NULL;
 	
 	while(p1->val != -1) {
 		if(head == NULL) {
 			head = p1;
		} else {
		 	p2->next = p1;
		}
		 
		p2 = p1;
		 
		p1 = (ListNode *) malloc(sizeof(ListNode)); //����Ϊp1 �����ڴ�ռ� 
		i++;
		cout << "Please input the " << i << " node," << "it's address is p" << i << "_addr = " << p1 <<endl;
        cin >> (p1->val);
	}
	free(p1);
	p2->next = NULL;
	p1 = NULL;
	cout << "End of creating ListNode." << endl;
    return head;
}

int main() {
	vector<int> v;
	struct ListNode* head = NULL;
    head = CreateListNode(head);
 
    Solution s;
    v = s.printListFromTailToHead2(head);
    for (int var : v) {
        cout << var << ' ';
	}
	return 0;
}

/*
	���ǿ�����printListFromTailToHead2()�����ȣ������ȶ�������ָ��(buf, pre)������head��ָͬ�������ͷ�ڵ㡣
	Ȼ��ͨ��head->next����ԭʼ������ͬʱ����bufָ���Ѿ��������Ľڵ�(buf = head->next)�������ڼ�headʼ��ָ��ͷ�ڵ㡣
	Ȼ�󣬸���head��>nextָ��buf����һ���ڵ�(head->next = buf->next)�����ţ�ͨ��buf->next = pre, ʹbufָ��ǰһ���ڵ㣬
	�����Ÿ���pre��ʹ��ָ��ǰ�ڵ㣬�Ա���һ�ָ��¡�
	
	��head->next�����������bufָ����ԭʼ�������һ���ڵ㣬head->next��ֵ��Ϊ��NULL�����ڴ�buf��ʼ���������ɷ����������
*/
