#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

//链表节点定义
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL) {
		}		
};

//链表从尾到头输出节点值
class Solution {
	public:
		//方法1，通过stack 这个container来实现反转链表
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
		
		//方法2，原地反转链表，不介入其它container
 	    //不断的使“下一个节点”指向“前一个”节点
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

//初始化链表 
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
		 
		p1 = (ListNode *) malloc(sizeof(ListNode)); //重新为p1 分配内存空间 
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
	我们看函数printListFromTailToHead2()。首先，我们先定义两个指针(buf, pre)，并与head共同指向链表的头节点。
	然后，通过head->next遍历原始链表，并同时更新buf指向已经遍历到的节点(buf = head->next)，而这期间head始终指向头节点。
	然后，更新head—>next指向buf的下一个节点(head->next = buf->next)。接着，通过buf->next = pre, 使buf指向前一个节点，
	紧接着更新pre，使其指向当前节点，以便下一轮更新。
	
	当head->next遍历完链表后，buf指向了原始链表最后一个节点，head->next的值变为了NULL。现在从buf开始遍历，即可反向遍历链表。
*/
