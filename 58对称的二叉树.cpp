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
    bool isSymmetrical(TreeNode* pRoot) {
    	if(pRoot == NULL) {
    		return true;
		}
		return IsSymmetrical(pRoot, pRoot);
    }
private:
	bool IsSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
		if(pRoot1 == NULL && pRoot2 == NULL) {
			return true;
		}
		if(pRoot1 == NULL || pRoot2 == NULL) {
			return false;
		}
		if(pRoot1->val != pRoot2->val) {
			return false;
		}
		return IsSymmetrical(pRoot1->left, pRoot2->right) && IsSymmetrical(pRoot1->right, pRoot2->left);
	}

};

int main() {

	return 0;
}

