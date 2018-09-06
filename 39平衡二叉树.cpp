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
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
}; 
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot == NULL) {
			return true;
		} 
		int left = GetDepth(pRoot->left);
		int right = GetDepth(pRoot->right);
		if(left > right + 1 || left + 1 < right) {
			return false;
		}
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
private:
	int GetDepth(TreeNode* pRoot) {
		if(!pRoot) {
			return 0;
		} 
		int left = GetDepth(pRoot->left);
		int right = GetDepth(pRoot->right);
		return left > right ? left + 1 : right + 1;
	}
};

int main() {

	return 0;
}

