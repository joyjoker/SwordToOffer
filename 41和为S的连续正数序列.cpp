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
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
*/
/*
�趨����ָ�룬һ��ָ���һ������һ��ָ�����һ�������ڴ�֮ǰ��Ҫ�趨��һ���������һ������ֵ���������������У�
���Կ��԰ѵ�һ������Ϊ1�����һ����Ϊ2����Ϊ��Ҫ���������������У���󲻿��ܺ͵�һ�����غϣ���
��һ�����ǲ��ϸı��һ���������һ������ֵ������ӵ�һ���������һ�����ĺ͸պ���Ҫ��ĺͣ���ô�����е�������ӵ�һ�������У�
�������Ҫ��ĺͣ���˵���ӵ�һ���������һ����֮��ķ�Χ̫����˼�С��Χ����Ҫ�ѵ�һ������ֵ��1��
ͬʱ�ѵ�ǰ�ͼ�ȥԭ���ĵ�һ������ֵ�����С��Ҫ��ĺͣ�˵����Χ̫С����˰����һ������1��ͬʱ�ѵ�ǰ�ĺͼ��ϸı�֮������һ������ֵ��
�����������޸ĵ�һ���������һ������ֵ������ȷ�����������������еĺ͵���S�������ˡ�
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        // ��λ�͵�λָ�� 
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

