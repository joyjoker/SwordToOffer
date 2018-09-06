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
class Solution {
public:
    int StrToInt(string str) {
    	bool isValid = false;
        // 非法输入
		if(str.empty()) {
			isValid = true;
			return 0;
		} 
		//指向字符数组的指针 
		const char* cstr = str.c_str(); 
		// 是否为负数
		bool isMinus = false;
		// 跳过前面的空白字符
		while(*cstr == ' ') {
			cstr++;
		} 
		if(*cstr == '+') {
			cstr++;
		} else if(*cstr == '-') {
			cstr++;
			isMinus = true;
		}
		//如果只输入了空白字符、符号位，或者什么都没输入，也为非法输入
		if(*cstr == '\0') {
			isValid = true;
			return 0;
		}
		// 后面的输入如果合法则转化为整数
		long num = 0; // 结果 
		while(*cstr != '\0') {
			// 输入不在 0 ~ 9 非法
			if(*cstr < '0' || *cstr > '9') {
				isValid = true;
				return 0;
			}
			// 对不包含符号位的合法字符进行转换
			num = 10 * num + (*cstr - '0'); 
			cstr++;
		} 
		// 确定正负
		num = isMinus ? (-1 * num) : num;
		// 判断是否溢出
		if(num > 0x7fffffff || num < (signed int)0x80000000) {
			isValid = true;
			return 0;
		} 
		return (int)num;
    }
};


int main() {
	string str = "-123";
    Solution s;
    cout << s.StrToInt(str);
    return 0;
}

