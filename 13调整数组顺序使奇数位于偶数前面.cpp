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
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
	所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
	*/
class Solution {
public:
	//双端队列实现 
    deque<int> reOrderArray(vector<int> &array) {
        deque<int> result;
        int num = array.size();
        for(int i = 0; i < num; i++) {
        	if(array[num - i - 1] % 2 == 1) {
        		result.push_back(array[i]);
			}
			if(array[i] % 2 == 0) {
				result.push_front(array[num - i - 1]);
			}
		}
		return result; 	//array.assign(result.begin(),result.end()); 无返回值情况 
    }
    
    //牛客网实现 类似冒泡 从后往前 奇偶交换 
    void reOrderArray1(vector<int> &array) {
    	for(int i = 0; i < array.size(); i++) {
    		for(int j = array.size() - 1; j > i; j--) {
    			if(array[j] % 2 == 1 && array[j - 1] % 2 == 0) {
    				swap(array[j], array[j - 1]);
				}
			}
		} 
	}
    	
};

int main() {
	//双端队列检测 
	vector<int> v = {1, 2, 3, 4, 5, 6};
	Solution s;
	deque<int> de = s.reOrderArray(v);
	for(int var : de) {
		cout << var << " " ;
	}
	cout << endl;
	//牛客网检测
	vector<int> v1 = {1, 2, 3, 4, 5, 6};
	Solution s1;
	s1.reOrderArray1(v1);
	for(int var : v1) {
		cout << var << " " ;
	}
	return 0;
}

