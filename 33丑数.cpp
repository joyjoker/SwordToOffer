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
		把只包含质因子2、3和5的数称作丑数（Ugly Number）。
		例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
		*/
		
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> result(index);
        if(index < 7) {  
        	return index; //1, 2, 3, 4, 5, 6 全是丑数 
		}
		result[0] = 1; 
		int t2 = 0, t3 = 0, t5 = 0;
		int i;
		for(i = 1; i < index; i++) {
			result[i] = min(result[t2] * 2, min(result[t3] * 3, result[t5] * 5));
			if(result[i] == result[t2] * 2) {
				t2++;
			}
			if(result[i] == result[t3] * 3) {
				t3++;
			}
			if(result[i] == result[t5] * 5) {
				t5++;
			}
		}
		return result[index - 1];
    }
};

int main() {
	Solution s;
	cout << s.GetUglyNumber_Solution(7);
	return 0;
}

