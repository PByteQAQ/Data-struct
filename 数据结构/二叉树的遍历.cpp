#include<stdio.h>
#include<stdlib.h>
typedef char Elemtype;
//创建结点
typedef struct TreeNode
{
	Elemtype data;
	TreeNode* lchild;
	TreeNode* rchild;
	
};
typedef TreeNode* BiTree;
char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;
//创建二叉树
void createtree(BiTree *T) {
	Elemtype ch;
	ch = str[idx++];
	if (ch == 0) {
		*T = NULL;
	}
	else {
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createtree(&(*T)->lchild);
		createtree(&(*T)->rchild);

	}
}
//前序遍历
void preorder(BiTree T) {
	if (T == NULL) {
		return;
	}
	else {
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
//中序遍历
void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	inOrder(T->lchild);
	printf("%c ", T->data);
	inOrder(T->rchild);
}
//后序遍历
void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c ", T->data);
}

int main(int argc, char const* argv[])
{
	BiTree T;
	createtree(&T);
	/*
	preOrder(T);
	printf("\n");


	inOrder(T);
	printf("\n");
	*/

	postOrder(T);
	printf("\n");

	return 0;
}