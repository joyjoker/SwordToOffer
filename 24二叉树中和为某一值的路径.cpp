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
	
	��Ŀ
		����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
		�������������ʹ��ǰ�������ʹ������ȫ�ֱ���result��tmp��result��������ս����tmp���������ʱ�����
	
	ÿ�α����������Ȱ�root��ֵѹ��tmp��Ȼ���жϵ�ǰroot�Ƿ�ͬʱ���㣺
	
	�������ֵ���Ϊ0��
	������Ϊ�գ�
	������Ϊ�ա�
	��������������ͽ�tmpѹ��result�У��������α���������������Ҫע����ǣ���������������ʱ��ȫ�ֱ���tmp�ǲ���յģ�ֱ�����˸��������tmp��
	*/

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
	// ��ʵ������׾���һ��ǰ����� ������  
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if(root == NULL) {
			return result; //�����³���� 
		}
		// �� 
		temp.push_back(root->val);
		if(expectNumber - root->val == 0 && root->left == NULL && root->right == NULL) {
			result.push_back(temp);
		} 
		
		// ��
		FindPath(root->left, expectNumber - root->val); 
		// �� 
		FindPath(root->right, expectNumber - root->val);
		
		temp.pop_back();
		return result;
    }
    
private:
	vector<vector<int>> result;
	vector<int> temp;
};

TreeNode *initBTree(int elements[], int size) {
	if(size < 1) {
		return NULL;
	}
	TreeNode **nodes = new TreeNode*[size];
 	for(int i = 0; i < size; i++) {
		if(elements[i] == 0) {
			nodes[i] = NULL;
		} else {
			nodes[i] = new TreeNode(elements[i]);
		}
	}
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(nodes[0]);
	int index = 1;
	TreeNode* node = NULL;
	while(index < size) {
		
		node = nodeQueue.front(); //��Ϊ���ڵ� 
		nodeQueue.pop();
		
		nodeQueue.push(nodes[index++]);
		node->left = nodeQueue.back();
		
		nodeQueue.push(nodes[index++]);
		node->right = nodeQueue.back();
	}
	return nodes[0];
}
int main() {
	int elements[7] = {1, 3, 2, 4, 0, 5, 6};
	TreeNode *root = initBTree(elements, 7);
	Solution s;
	vector<vector<int>> result = s.FindPath(root, 8);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[0].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

