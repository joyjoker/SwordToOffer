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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot == NULL) {
        	return result;
		}
		// �ֱ�洢������ڵ��ż����ڵ� 
		stack<TreeNode*> stackL, stackR;
		// ��ʱ�洢ÿ��� val 
		vector<int> temp; 
		stackL.push(pRoot);
		temp.push_back(pRoot->val);
		result.push_back(temp);
		temp.clear(); 
		// ��ǰ�������Ľڵ�
		TreeNode* currentNode = NULL;
		while(!stackL.empty() || !stackR.empty()) {
			while(!stackL.empty()) {
				currentNode = stackL.top();
				stackL.pop();
				if(currentNode->right) {
					stackR.push(currentNode->right);
					// ��ʱ��� 
					temp.push_back(currentNode->right->val);
				}
				if(currentNode->left) {
					stackR.push(currentNode->left);
					temp.push_back(currentNode->left->val);
				}
			}
			if(!temp.empty()) {
				result.push_back(temp);
				temp.clear();
			}
			while(!stackR.empty()) {
				currentNode = stackR.top();
				stackR.pop();
				if(currentNode->left) {
					stackL.push(currentNode->left);
					temp.push_back(currentNode->left->val);
				}
				if(currentNode->right) {
					stackL.push(currentNode->right);
					temp.push_back(currentNode->right->val);
				}
			}
			if(!temp.empty()) {
				result.push_back(temp);
				temp.clear();
			}
		}
		return result;
    }
    
};


int main() {
	
	return 0;
}

