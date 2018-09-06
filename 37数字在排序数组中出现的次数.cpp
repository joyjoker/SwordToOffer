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
//统计一个数字在排序数组中出现的次数。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) {
        	return 0;
		}
		int first = GetFirstK(data, k, 0, data.size() - 1);
		cout << first << " ";
		int last = GetLastK(data, k, 0, data.size() - 1);
		cout << last << " ";
		if(first != -1 && last != -1) {
			return last - first + 1;
		}
		return 0;
    }
private:
	// 迭代实现找到第一个k
	int GetFirstK(vector<int> data, int k, int begin, int end) {
		if(begin > end) {
			return -1;
		} 
		int middleIndex = (begin + end) / 2;
		int middleData = data[middleIndex];
		
		if(middleData == k)  {
			if(middleIndex > 0 && middleData != data[middleIndex - 1] || middleIndex == 0) {
				return middleIndex;
			} else {
				end = middleIndex - 1;
			} 
			
		} else if(middleData > k) {
			end = middleIndex - 1;
		}else {
			begin = middleIndex + 1;
		}
		return GetFirstK(data, k, begin, end);
	} 
	//循环实现找到最后一个k 
	int GetLastK(vector<int> data, int k, int begin, int end) {
		int length = data.size();
		int middleIndex = length / 2;
		int middleData = data[middleIndex]; 
		
		while(begin <= end) {
			if(middleData == k) {
				if(middleIndex < length - 1 && middleData != data[middleIndex + 1] || middleIndex == length - 1) {
					return middleIndex;
				} else {
					begin = middleIndex + 1;
				}
			} else if(middleData > k) {
				end = middleIndex - 1;
			}else {
				begin = middleIndex + 1;
			}
			middleIndex = (begin + end)  / 2;
            middleData = data[middleIndex];
		}
		
		return -1;
 	}	
};

int main() {
	Solution s;
	vector<int> data = { 4, 4, 4, 4, 4 };
	cout << s.GetNumberOfK(data, 4);
	return 0;
}

