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
		��Ŀ����
		����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
		*/
		
		/*
		ʹ������stack��һ��Ϊ����ջ����һ��Ϊ����ջ������ջ���ڴ洢�������ݣ�����ջ���ڴ洢��Сֵ��
		��ջ��ʱ���������յ�����ջ��ѹ������3����Ȼ����3����Сֵ������Ҳ����Сֵѹ�븨��ջ��������������ջ��ѹ������4��
		����4����֮ǰ����Сֵ���������ֻҪ������ջ����ѹ�븨��ջ��

		��ջ��ʱ�򣺵�����ջ�͸���ջ��ջ��Ԫ����ͬ��ʱ�򣬸���ջ��ջ��Ԫ�س�ջ����������ջ��ջ��Ԫ�س�ջ��

		���ջ��Ԫ�ص�ʱ��ֱ�ӷ�������ջ��ջ��Ԫ�ء�

		ջ��СԪ�أ�ֱ�ӷ��ظ���ջ��ջ��Ԫ�ء�
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
	stack<int> mindata;//����ջ 
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

