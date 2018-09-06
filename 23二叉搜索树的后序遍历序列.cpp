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
		输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
		*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		return bst(sequence, 0, sequence.size() - 1);
    }
private:
	bool bst(vector<int> seq, int begin, int end) {
		
		if(seq.empty() || begin > end) {
			return false;
		}
		//后序遍历 根节点为数组末尾元素 
		int root = seq[end];
		
		//左子树节点全部小于根节点 
		int i = begin;
		for( ; i < end; i++) { //找到左右子树分界点 
			if(seq[i] > root) {
				break;
			}
		} 
		//右子树节点全部大于根节点 
		for(int j = i; j < end; j++) { // 判断是否符合二叉搜索树 
			if(seq[j] < root) {
				return false;
			}
		}
		
		//判断左子树是否符合二叉搜索树
		bool left = true;
		if(i > begin) { //保证有左子树 
		 	left = bst(seq, 0, i - 1); 
		}
		//判断左子树是否符合二叉搜索树 
		bool right = true;
		if(i > end) { //保证有右子树 
		 	right = bst(seq, i, end - 1); 
		}
		return left && right;
	}
};


int main() {
	vector<int> v = {5, 7, 6, 9, 11, 10, 8};
	Solution s;
	cout << s.VerifySquenceOfBST(v);
	return 0;
}

