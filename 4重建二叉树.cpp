#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL){ }
};


//��ָofferԭ��棬��������������С�������������ؽ�������
TreeNode* ConstructByPreIn(int *preOrder, int *inOrder, int length) {
	if (preOrder == NULL || inOrder == NULL || length <= 0) return NULL;
	//�½����,��ǰ�������е�һ��Ԫ��Ϊ�����
	int root_val = preOrder[0];	
	TreeNode *root = new TreeNode(root_val);
	//��ʼ��������������
	int leftLength = 0;
	int rightLength = 0;
	//�������������ҵ����ڵ��λ�ã��ش��ڣ�
	for (int i = 0; i < length; i++)
	{
		if (inOrder[i] == root_val)
		{
			leftLength = i;
			rightLength = length - i - 1;
			break;
		}
	}
	//���������У����ڵ���ߵ�Ϊ���������ұߵ�Ϊ������
	int *leftPre = preOrder + 1;
	int *leftIn = inOrder;
	int *rightPre = preOrder + leftLength + 1;
	int *rightIn = inOrder + leftLength + 1;
	//�ݹ鹹����������
	root->left = ConstructByPreIn(leftPre, leftIn, leftLength);
	root->right = ConstructByPreIn(rightPre, rightIn, rightLength);
	return root;

}

//ţ�����汾�������������������ؽ�������
TreeNode *reConstructBinaryTree(vector<int>preOrder, vector<int>inOrder) {
	if(preOrder.empty() || inOrder.empty()) {
		return NULL;
	}
	
	//�½��ڵ� ��ǰ�����еĵ�һ��Ԫ��Ϊ���ڵ� 
	int root_val = preOrder[0];
	TreeNode *root = new TreeNode(root_val);
	
	//��ʼ��������������
	int leftLength = 0;
	int rightLength = 0;
	for(int i = 0; i < inOrder.size(); i++) {
		if(inOrder[i] == root_val) {
			leftLength = i;
			rightLength = inOrder.size() - i - 1;
			break;
		}
	} 
	
	//���������� ���ڵ����Ϊ������ �ұ�Ϊ������
	vector<int> leftPre (preOrder.begin() + 1, preOrder.begin() + 1 + leftLength);
	vector<int> leftIn (inOrder.begin(), inOrder.begin() + leftLength);
	vector<int> rightPre (preOrder.begin() + leftLength + 1, preOrder.begin() + leftLength + rightLength + 1);
	vector<int> rightIn (inOrder.begin() + leftLength + 1, inOrder.begin() + leftLength+ rightLength + 1 );
	
	root->left =  reConstructBinaryTree(leftPre, leftIn);
	root->right =  reConstructBinaryTree(rightPre, rightIn);
	return root;
}

//�������
void preOrder(TreeNode *root) {
	if(root == NULL) {
		return; 
	}
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
} 

//�������
void inOrder(TreeNode *root) {
	if(root == NULL) {
		return; 
	}
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

//�������
void postOrder(TreeNode *root) {
	if(root == NULL) {
		return; 
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}


int main() {
	
	//ԭ��汾��������
	int preO[] = { 1,2,4,7,3,5,6,8 };
	int inO[] = { 4,7,2,1,5,3,8,6 };
	TreeNode *tree = ConstructByPreIn(preO, inO, 8);
	preOrder(tree);    //�������
	std::cout << std::endl;
	inOrder(tree);     //�������
	std::cout << std::endl;
	
	//ţ�����汾��������
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	TreeNode *tree2 = reConstructBinaryTree(pre, in);
	preOrder(tree2);    //�������
	std::cout << std::endl;
	inOrder(tree2);     //�������
	std::cout << std::endl;
	return 0;
}


/*
//�������
void LevelOrder(TreeNode *root)
{
	if (root == NULL) return;
	deque<TreeNode *> NodeDeque;
	NodeDeque.push_front(root);
	while (!NodeDeque.empty())
	{
		//������׽��Ԫ��ֵ
		TreeNode *node = NodeDeque.front();
		cout << node->val << " ";
		if (node->left != NULL)
			NodeDeque.push_back(node->left);
		if (node->right != NULL)
			NodeDeque.push_back(node->right);
		//����
		NodeDeque.pop_front();
	}
}
 
//�����������ģ�����
void LevelOrder2(TreeNode *root)
{
	if (root == NULL) return;
	//ģ�����
	TreeNode* nodeDeque[1024];
	int front = -1;    //��ͷָ���ʼ��-1��
	int rear = 0;      //��β��ʼ��0���п�Ϊfront == rear
	nodeDeque[rear] = root;    //���ڵ����
	while (front != rear)
	{
		++front;    //��ͷ����
		TreeNode *node = nodeDeque[front];    //ȡ��ͷԪ��
		cout << node->val << ' ';
		if (node->left != NULL)
		{
			//���Ӳ�Ϊ�գ��������
			nodeDeque[++rear] = node->left;
		}
		if (node->right != NULL)
		{
			//�Һ��Ӳ�Ϊ�գ��к������
			nodeDeque[++rear] = node->right;
		}
	}
*/ 
