#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode		= (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild		= NULL;
	NewNode->RightSibling	= NULL;
	NewNode->Data			= NewData;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);

	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);

	Root->LeftChild		= NULL;
	Root->RightSibling	= NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
		{
			TempNode = TempNode->RightSibling;
		}
		TempNode->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	int i = 0;

	for (i = 0; i < Depth; i++)
		printf(" ");

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	
	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

void LCRS_PrintNode(LCRSNode* Node, int level)
{
	printf("NodeData : %c, level : %d\n", Node->Data, level);
}

void LCRS_PrintNodesAtLevel(LCRSNode* Root, int level)
{
	int i;

	if (level <= 0)
	{
		printf("Only exist Level : 0\n");
		if (Root->RightSibling == NULL)
		{
			LCRS_PrintNode(Root, level);
		}
		else
		{
			LCRSNode* TempNode = Root->RightSibling;
			while (TempNode->RightSibling != NULL)
			{
				LCRS_PrintNode(TempNode, level);
				TempNode = TempNode->RightSibling;
			}
			LCRS_PrintNode(TempNode, level);
		}
	}
	else
	{
		LCRSNode* Temp_RootNode		= Root;
		LCRSNode* Temp_ParentNode	= NULL;
		int t_level = level - 1;

		while (t_level != 0)
		{
			t_level--;
			Temp_RootNode = Temp_RootNode->LeftChild;
		}

		Temp_ParentNode = Temp_RootNode;

		while (Temp_ParentNode != NULL)
		{
			while (Temp_ParentNode->LeftChild != NULL)
			{
				LCRS_PrintNode(Temp_ParentNode->LeftChild, level);
				Temp_ParentNode->LeftChild = Temp_ParentNode->LeftChild->RightSibling;
			}
			Temp_ParentNode = Temp_ParentNode->RightSibling;
		}
	}
}