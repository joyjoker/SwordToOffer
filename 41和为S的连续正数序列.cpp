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
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/
/*
设定两个指针，一个指向第一个数，一个指向最后一个数，在此之前需要设定第一个数和最后一个数的值，由于是正数序列，
所以可以把第一个数设为1，最后一个数为2（因为是要求是连续正数序列，最后不可能和第一个数重合）。
下一步就是不断改变第一个数和最后一个数的值，如果从第一个数到最后一个数的和刚好是要求的和，那么把所有的数都添加到一个序列中；
如果大于要求的和，则说明从第一个数到最后一个数之间的范围太大，因此减小范围，需要把第一个数的值加1，
同时把当前和减去原来的第一个数的值；如果小于要求的和，说明范围太小，因此把最后一个数加1，同时把当前的和加上改变之后的最后一个数的值。
这样，不断修改第一个数和最后一个数的值，就能确定所有连续正数序列的和等于S的序列了。
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        // 高位和低位指针 
		int phigh = 2, plow = 1;
		vector<vector<int>> result;
		while(plow < phigh) {
			int curSum = (phigh + plow) * (phigh - plow + 1) / 2; 
			if(curSum < sum) {
				phigh++;
			} 
			if(curSum == sum) {
				vector<int> temp;
				for(int i = plow; i <= phigh; i++) {
					temp.push_back(i);
				}
				result.push_back(temp);
				plow++;
			}
			if(curSum > sum) {
				plow++;
			}	
		} 
		return result;
    }
};

int main() {
	Solution s;
	vector<vector<int>> result = s.FindContinuousSequence(6);
	for(vector<int> v : result) {
		for(int r : v) {
			cout << r << " ";
		}
		cout << endl;
	}
	return 0;
}

