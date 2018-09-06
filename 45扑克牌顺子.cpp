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
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) {
        	return false;
		}
		sort(numbers.begin(), numbers.end());
		int count0 = 0, need0 = 0; // 有几个0 需要几个0
		for(int i = 0; i < numbers.size(); i++) {
			if(numbers[i] == 0) {
				count0++;
			}else if(i < 4) {
				if(numbers[i + 1] == numbers[i]) { // 出现对子 不可能是顺子 
					return false;
				}
				need0 += numbers[i + 1] - numbers[i] - 1;
			}
		} 
	//	cout << need0 << " " << count0 << " ";
		if(need0 > count0) {
			return false;
		}
		return true;
    }
};


int main() {
	vector<int> v = {0,3,2,6,4};
	Solution s;
	cout << s.IsContinuous(v);
	return 0;
}

