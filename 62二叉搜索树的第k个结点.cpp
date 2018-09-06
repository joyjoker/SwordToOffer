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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot == NULL || k < 1) {
        	return NULL;
		}
		return KthNodeCore(pRoot, k);
    }
private:
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k) { // 一定加引用 
		// 目标节点 
		TreeNode *target = NULL;
		if(pRoot->left) {
			target = KthNodeCore(pRoot->left, k);
		} 
		// 如果没有找到target，则减小k，如果k等于1，说明到了第k大的数
		if(target == NULL) {
			if(k == 1) {
				target = pRoot;
			}
			k--;
		}
		if(pRoot->right && target == NULL) {
			target = KthNodeCore(pRoot->right, k);
		}
		return target; 
	}
};

int main() {

	return 0;
}

