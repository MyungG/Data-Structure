#include "ExpressionTree.h"

ETNode* ET_CreateNode(ElementType NewData)
{
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void ET_DestroyNode(ETNode* Node)
{
	free(Node);
}

void ET_DestroyTree(ETNode* Node)
{
	if (Node == NULL)
		return;

	ET_DestroyTree(Node->Left);				// 왼쪽 하위 트리 소멸
	ET_DestroyTree(Node->Right);			// 오른쪽 하위 트리 소멸
	ET_DestroyNode(Node);					// 루트 노드 소멸
}

void ET_PreorderPrintTree(ETNode* Node)
{
	if (Node == NULL)
		return;

	printf("  %c", Node->Data);				// 루트 노드 출력
	ET_PreorderPrintTree(Node->Left);		// 왼쪽 하위 트리 출력
	ET_PreorderPrintTree(Node->Right);		// 오른쪽 하위 트리 출력
}

void ET_InorderPrintTree(ETNode* Node)
{
	if (Node == NULL)
		return;

	printf("(");
	ET_InorderPrintTree(Node->Left);		// 왼쪽 하위 트리 출력

	printf("  %c", Node->Data);				// 루트 노드 출력

	ET_InorderPrintTree(Node->Right);		// 오른쪽 하위 트리 출력
	printf(")");
}

void ET_PostorderPrintTree(ETNode* Node)
{
	if (Node == NULL)
		return;

	ET_PostorderPrintTree(Node->Left);		// 왼쪽 하위 트리 출력
	ET_PostorderPrintTree(Node->Right);		// 오른쪽 하위 트리 출력
	printf("  %c", Node->Data);				// 루트 노드 출력
}

void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node)
{
	int  len	= strlen(PostfixExpression);
	char Token	= PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token)
	{
		// 연산자인 경우
	case '+': case '-': case '*': case '/':
		(*Node) = ET_CreateNode(Token);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
		break;

		// 피연산자인 경우
	default:
		(*Node) = ET_CreateNode(Token);
		break;
	}
}

double ET_Evaluate(ETNode* Tree)
{
	char Temp[2];

	double Left	  = 0;
	double Right  = 0;
	double Result = 0;

	if (Tree == NULL)
		return 0;

	switch (Tree->Data)
	{
		// 연산자인 경우
	case '+': case '-': case '*': case '/':
		Left = ET_Evaluate(Tree->Left);
		Right = ET_Evaluate(Tree->Right);

		if		(Tree->Data == '+') Result = Left + Right;
		else if (Tree->Data == '-') Result = Left - Right;
		else if (Tree->Data == '*') Result = Left * Right;
		else if (Tree->Data == '/') Result = Left / Right;
		break;

		// 피연산자인 경우
	default:
		memset(Temp, 0, sizeof(Temp));
		Temp[0] = Tree->Data;
		Result  = atof(Temp);
		break;
	}

	return Result;
}