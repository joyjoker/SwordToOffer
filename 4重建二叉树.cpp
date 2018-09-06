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


//剑指offer原书版，根据先序遍历序列、中序遍历序列重建二叉树
TreeNode* ConstructByPreIn(int *preOrder, int *inOrder, int length) {
	if (preOrder == NULL || inOrder == NULL || length <= 0) return NULL;
	//新建结点,当前先序序列第一个元素为根结点
	int root_val = preOrder[0];	
	TreeNode *root = new TreeNode(root_val);
	//初始化左右子树参数
	int leftLength = 0;
	int rightLength = 0;
	//在中序序列中找到根节点的位置（必存在）
	for (int i = 0; i < length; i++)
	{
		if (inOrder[i] == root_val)
		{
			leftLength = i;
			rightLength = length - i - 1;
			break;
		}
	}
	//中序序列中，根节点左边的为左子树，右边的为右子树
	int *leftPre = preOrder + 1;
	int *leftIn = inOrder;
	int *rightPre = preOrder + leftLength + 1;
	int *rightIn = inOrder + leftLength + 1;
	//递归构建左右子树
	root->left = ConstructByPreIn(leftPre, leftIn, leftLength);
	root->right = ConstructByPreIn(rightPre, rightIn, rightLength);
	return root;

}

//牛客网版本，根据先序中序序列重建二叉树
TreeNode *reConstructBinaryTree(vector<int>preOrder, vector<int>inOrder) {
	if(preOrder.empty() || inOrder.empty()) {
		return NULL;
	}
	
	//新建节点 当前先序列的第一个元素为根节点 
	int root_val = preOrder[0];
	TreeNode *root = new TreeNode(root_val);
	
	//初始化左右子树长度
	int leftLength = 0;
	int rightLength = 0;
	for(int i = 0; i < inOrder.size(); i++) {
		if(inOrder[i] == root_val) {
			leftLength = i;
			rightLength = inOrder.size() - i - 1;
			break;
		}
	} 
	
	//中序序列中 根节点左边为左子树 右边为右子树
	vector<int> leftPre (preOrder.begin() + 1, preOrder.begin() + 1 + leftLength);
	vector<int> leftIn (inOrder.begin(), inOrder.begin() + leftLength);
	vector<int> rightPre (preOrder.begin() + leftLength + 1, preOrder.begin() + leftLength + rightLength + 1);
	vector<int> rightIn (inOrder.begin() + leftLength + 1, inOrder.begin() + leftLength+ rightLength + 1 );
	
	root->left =  reConstructBinaryTree(leftPre, leftIn);
	root->right =  reConstructBinaryTree(rightPre, rightIn);
	return root;
}

//先序遍历
void preOrder(TreeNode *root) {
	if(root == NULL) {
		return; 
	}
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
} 

//中序遍历
void inOrder(TreeNode *root) {
	if(root == NULL) {
		return; 
	}
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

//后序遍历
void postOrder(TreeNode *root) {
	if(root == NULL) {
		return; 
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}


int main() {
	
	//原书版本函数测试
	int preO[] = { 1,2,4,7,3,5,6,8 };
	int inO[] = { 4,7,2,1,5,3,8,6 };
	TreeNode *tree = ConstructByPreIn(preO, inO, 8);
	preOrder(tree);    //先序输出
	std::cout << std::endl;
	inOrder(tree);     //中序输出
	std::cout << std::endl;
	
	//牛客网版本函数测试
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	TreeNode *tree2 = reConstructBinaryTree(pre, in);
	preOrder(tree2);    //先序输出
	std::cout << std::endl;
	inOrder(tree2);     //中序输出
	std::cout << std::endl;
	return 0;
}


/*
//层序遍历
void LevelOrder(TreeNode *root)
{
	if (root == NULL) return;
	deque<TreeNode *> NodeDeque;
	NodeDeque.push_front(root);
	while (!NodeDeque.empty())
	{
		//输出队首结点元素值
		TreeNode *node = NodeDeque.front();
		cout << node->val << " ";
		if (node->left != NULL)
			NodeDeque.push_back(node->left);
		if (node->right != NULL)
			NodeDeque.push_back(node->right);
		//出队
		NodeDeque.pop_front();
	}
}
 
//层序遍历数组模拟队列
void LevelOrder2(TreeNode *root)
{
	if (root == NULL) return;
	//模拟队列
	TreeNode* nodeDeque[1024];
	int front = -1;    //队头指针初始化-1；
	int rear = 0;      //队尾初始化0，判空为front == rear
	nodeDeque[rear] = root;    //根节点入队
	while (front != rear)
	{
		++front;    //队头出队
		TreeNode *node = nodeDeque[front];    //取队头元素
		cout << node->val << ' ';
		if (node->left != NULL)
		{
			//左孩子不为空，左孩子入队
			nodeDeque[++rear] = node->left;
		}
		if (node->right != NULL)
		{
			//右孩子不为空，有孩子入队
			nodeDeque[++rear] = node->right;
		}
	}
*/ 
