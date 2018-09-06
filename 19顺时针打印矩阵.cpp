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
		输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
		如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
		则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
		*/
class Solution {
	public:
		vector<int> printMatrix(vector<vector<int>> matrix) {
			int rows = matrix.size(); // 行数 
			int cols = matrix[0].size(); // 列数
			
			vector<int> result; //结果数组
			if(rows == 0 && cols == 0) {
				return result;
			}
			int left = 0, right = cols- 1, top = 0, bottom = rows - 1;
			while(left <= right && top <= bottom) {
				// 从左到右
				for(int i = left; i <= right; i++) {
					result.push_back(matrix[top][i]);
				} 
				// 从上到下 
				for(int i = top + 1; i <= bottom; i++) {
					result.push_back(matrix[i][right]);
				} 
				// 从右到左 
				if(top != bottom) { // 如果只有一行 
					for(int i = right - 1; i >= left; i--) {
						result.push_back(matrix[bottom][i]);
					} 
				}
				
				// 从下到上
				if(left != right) { // 如果只有一列 
					for(int i = bottom - 1; i > top; i--) { //没有等于 
						result.push_back(matrix[i][left]);
					} 
				} 
				
				left++, right--, top++, bottom--; 
			}
			
			return result; 
		}
};

int main() {
    vector<vector<int>> matrix = {{1,   2,  3,  4}, 
								  {5,   6,  7,  8},
								  {9,  10, 11, 12}, 
								  {13, 14, 15, 16}};
	vector<vector<int>> matrix1 = {{1}, 
								   {2},
								   {3}, 
								   {4}, 
								   {5}};
								  
	Solution s;
	vector<int> result = s.printMatrix(matrix);
	for(int v : result) {
		cout << v << " ";
	}
	return 0;
}

