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
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0) {
        	return -1;
		}
		map<char, int> item;
		for(int i = 0; i < str.size(); i++) {
			item[str[i]]++;
		}
		for(int i = 0; i < str.size(); i++) {
			if(item[str[i]] == 1) {
				return i;
			}
			
		}
		return -1;
    }
};
int main() {
	Solution s;
	cout << s.FirstNotRepeatingChar("qqa");
	return 0;
}

