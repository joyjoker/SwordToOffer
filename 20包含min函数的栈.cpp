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
		定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
		*/
		
		/*
		使用两个stack，一个为数据栈，另一个为辅助栈。数据栈用于存储所有数据，辅助栈用于存储最小值。
		入栈的时候：首先往空的数据栈里压入数字3，显然现在3是最小值，我们也把最小值压入辅助栈。接下来往数据栈里压入数字4。
		由于4大于之前的最小值，因此我们只要入数据栈，不压入辅助栈。

		出栈的时候：当数据栈和辅助栈的栈顶元素相同的时候，辅助栈的栈顶元素出栈。否则，数据栈的栈顶元素出栈。

		获得栈顶元素的时候：直接返回数据栈的栈顶元素。

		栈最小元素：直接返回辅助栈的栈顶元素。
		*/
class Solution {
public:
    void push(int value) {
        data.push(value);
		if(mindata.empty()) {
			mindata.push(value);
		} 
		if(mindata.top() >= value) {
			mindata.push(value);
		}
    }
    void pop() {
    	if(data.top() == mindata.top()) {
    		mindata.pop();
		}
        data.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return mindata.top();
    }
private:
	stack<int> data; 
	stack<int> mindata;//辅助栈 
};

int main() {
	Solution s;
	s.push(4);
	s.push(3);
	s.push(4);
	s.push(1);
	s.push(0);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	return 0;
}

