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
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.empty()) {
    		return 0;
		}
		//�ֱ�Ϊ ���� �� ��ǰ���� 
		int maxSum = array[0]; // ��ʼֵ��������Ϊ0 ��ֹֻ�и��� 
		int curSum = array[0];
		for(int i = 1; i < array.size(); i++) {
			//�����ǰ��С�ڵ����� ˵��֮ǰ�ĺ�Ϊ0�� ������
			if(curSum <= 0) {
				curSum = array[i];
			} else {
				curSum += array[i];
			}
			if(curSum > maxSum) {
				maxSum = curSum;
			}
		} 
		return maxSum;
    }
};

int main() {
	Solution s;
	vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
	cout << s.FindGreatestSumOfSubArray(array);
	return 0;
}

