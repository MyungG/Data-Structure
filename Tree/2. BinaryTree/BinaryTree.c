#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode	= (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left		= NULL;
	NewNode->Right		= NULL;
	NewNode->Data		= NewData;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_DestroyTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_DestroyTree(Node->Left);			// 왼쪽 하위 트리 소멸
	SBT_DestroyTree(Node->Right);			// 오른쪽 하위 트리 소멸
	SBT_DestroyNode(Node);				// 루트 노드 소멸
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	printf("  %c", Node->Data);			// 루트 노드 출력
	SBT_PreorderPrintTree(Node->Left);		// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Right);		// 오른쪽 하위 트리 출력
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_InorderPrintTree(Node->Left);		// 왼쪽 하위 트리 출력
	printf("  %c", Node->Data);			// 루트 노드 출력
	SBT_InorderPrintTree(Node->Right);		// 오른쪽 하위 트리 출력
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_PostorderPrintTree(Node->Left);		// 왼쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Right);		// 오른쪽 하위 트리 출력
	printf("  %c", Node->Data);			// 루트 노드 출력
}
