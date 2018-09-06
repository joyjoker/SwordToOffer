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
    int TreeDepth1(TreeNode* pRoot) {
        if(pRoot == NULL) {
        	return 0;
		}
		int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return (left > right) ? left + 1 : right + 1;
    }
    // ·ÇµÝ¹é±éÀú
	int TreeDepth(TreeNode* pRoot) {
		if(pRoot == NULL) {
			return 0;
		}
		queue<TreeNode*> queue;
		queue.push(pRoot);
		int depth = 0;
		while(!queue.empty()) {
			depth++;
			int size = queue.size();
		
			for(int i = 0; i < size; i++) {
				TreeNode* node = queue.front();
				queue.pop();
				if(node->left) {
					queue.push(node->left);
				}
				if(node->right) {
					queue.push(node->right);
				}
			}
		}
		return depth;
	} 
};

int main() {

	return 0;
}

