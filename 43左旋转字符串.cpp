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
    string LeftRotateString(string str, int n) {
        string result = str;
        int length = result.size();
        if(length < 0) {
        	return NULL;
		}
		//if(0 <= n <= length) {
			int firstBegin = 0, firstEnd = n - 1;
			int secondBegin = n, secondEnd = length - 1;
			ReverseString(result, firstBegin, firstEnd);
			ReverseString(result, secondBegin, secondEnd);
			ReverseString(result, firstBegin, secondEnd);	
	//	}
		return result;
    }
    
private:
	void ReverseString(string &str, int begin, int end) {
		while(begin < end)
			swap(str[begin++], str[end--]);
	}
};

int main() {
	Solution s;
	cout << s.LeftRotateString(",", 6);
	return 0;
}

