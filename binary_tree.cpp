/* I mainly wrote this in c programing language, but the codes involve some c++ language for convenience*/
#include <iostream>
#include <stack>

#define ElemType int
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}*BiTree;

void CreateBiTree_preorder(BiTree *T)
{
	ElemType e;
	std::cin >> e;
	if (e == 0)
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		CreateBiTree_preorder(&(*T)->lchild);
		CreateBiTree_preorder(&(*T)->rchild);
	}
}

void PreorderTraverse_recursion(BiTree T, void visit(ElemType i))
{
	if (!T)
		return;
	visit(T->data);
	PreorderTraverse_recursion(T->lchild, visit);
	PreorderTraverse_recursion(T->rchild, visit);
}

void PreorderTraverse_stack(BiTree T, void visit(ElemType i))
{
	std::stack <BiTree>stk;
	while (true)
	{
		while (T)
		{
			visit(T->data);
			stk.push(T->rchild);
			T = T->lchild;
		}
		if (stk.empty())
			break;
		T = stk.top();
		stk.pop();
	}
}

void InorderTraverse_recursion(BiTree T, void visit(ElemType i))
{
	if (!T)
		return;
	InorderTraverse_recursion(T->lchild, visit);
	visit(T->data);
	InorderTraverse_recursion(T->rchild, visit);
}

void InorderTraverse_stack(BiTree T, void visit(ElemType i))
{
	std::stack <BiTree>stk;
	while (true)
	{
		while (T)
		{
			stk.push(T);
			T = T->lchild;
		}
		if (stk.empty())
			break;
		T = stk.top();
		stk.pop();
		visit(T->data);
		T = T->rchild;
	}
}

void PostorderTraverse_recursion(BiTree T, void visit(ElemType i))
{
	if (!T)
		return;
	PostorderTraverse_recursion(T->lchild, visit);
	PostorderTraverse_recursion(T->rchild, visit);
	visit(T->data);
}

void visit(ElemType e)
{
	std::cout << e << " ";
}

//execution example:
int main()
{
	BiTree T;
	std::cout << "enter the preorder sequence(integer type), use 0 to represent NULL node" << std::endl;
	CreateBiTree_preorder(&T);

	std::cout << "Preorder Traverse:" << std::endl;

	std::cout << "recursion version:" << std::endl;
	PreorderTraverse_recursion(T,visit);
	std::cout << std::endl;

	std::cout << "stack version:" << std::endl;
	PreorderTraverse_stack(T, visit);
	std::cout << std::endl << std::endl;

	std::cout << "Inorder Traverse:" << std::endl;

	std::cout << "recursion version:" << std::endl;
	InorderTraverse_recursion(T, visit);
	std::cout << std::endl;

	std::cout << "stack version:" << std::endl;
	InorderTraverse_stack(T, visit);
	std::cout << std::endl << std::endl;

	std::cout << "Postorder Traverse:" << std::endl;
	PostorderTraverse_recursion(T, visit);
	std::cout << std::endl;
    return 0;
}

