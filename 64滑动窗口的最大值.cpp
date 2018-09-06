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
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		
		vector<int> maxInWindows;
		if(num.size() >= size && size >= 1) {	 
			// 存储的是数组索引 
			deque<int> index;  
			for(unsigned int i = 0; i < size; i++) {
				while(!index.empty() && num[i] >= num[index.back()]) {
					index.pop_back();
				}
				index.push_back(i);
			}
			for(unsigned int i = size; i < num.size(); i++) {
				maxInWindows.push_back(num[index.front()]);
				while(!index.empty() && num[i] >= num[index.back()]) {
					index.pop_back();
				}
				
				// 控制窗口大小 为size 如果不判断是否非空 可能越界 
				if(!index.empty() && index.front() <= int(i - size)) {
					index.pop_front();
				}
				index.push_back(i);
			}
			maxInWindows.push_back(num[index.front()]);
		}  
		return maxInWindows; 
    }
};

int main() {
	Solution s;
	vector<int> num = {2,3,4,2,6,2,5,1}, result;
	result = s.maxInWindows(num, 3);
	for(int v : result) {
		cout << v << " "; 
	}
	return 0;
}

