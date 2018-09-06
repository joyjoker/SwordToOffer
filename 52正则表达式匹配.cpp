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
	    bool match(char* str, char* pattern) {
			if(str == NULL || pattern == NULL) {
				return false;
			}
			return matchCore(str, pattern);
	    }
	    bool matchCore(char *str, char* pattern) {
	    	if(*str == '\0' && *pattern == '\0') { // 迭代终止条件 
	    		return true;
			} 
			if(*str != '\0' && *pattern == '\0') { // 迭代终止条件 
	    		return false;
			} 
			
			// 在模式串 需要考虑下一个字符
			// 如果模式串的下一个字符是'*'，则进入状态机的匹配
	        if(*(pattern + 1) == '*'){
	            // 如果字符串和模式串相等，或者模式串是'.'，并且字符串没有到结尾，则继续匹配
	            if(*str == *pattern || (*pattern == '.' && *str != '\0')){
	                // 进入下一个状态，就是匹配到了一个
	                return matchCore(str + 1, pattern + 2) ||
	                    // 保持当前状态，就是继续那这个'*'去匹配
	                    matchCore(str + 1, pattern) ||
	                    // 跳过这个'*'
	                    matchCore(str, pattern + 2);
	            }
	            // 如果字符串和模式串不相等，则跳过当前模式串的字符和'*'，进入新一轮的匹配
	            else{
	                // 跳过这个'*'
	                return matchCore(str, pattern + 2);
	            }
	        }
	        // 如果字符串和模式串相等，或者模式串是'.'，并且字符串没有到结尾，则继续匹配
	        if(*str == *pattern || (*pattern == '.' && *str != '\0')){
	            return matchCore(str + 1, pattern + 1);
	        }
	        	return false;
		}
};

int main() {
	Solution s;
	char str[] = " ";
	char pattern[] = " ";
	cout << s.match(str, pattern);
	return 0;
}

