#include <cstdio>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()) {
        	while(stack1.size() > 0) {
        		int data = stack1.top();
        		stack1.pop();
        		stack2.push(data);
			}		
		} 
		int pop_element = stack2.top();
		stack2.pop();
		return pop_element;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};





int main() {
	Solution s;
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(3);
	
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	
	return 0;
} 
