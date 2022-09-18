#include "Stack.h"

void Create_Stack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void Destroy_Stack(LinkedListStack* Stack)
{
	free(Stack);
}

Node* Create_Node(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(NewData));

	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}

void Destroy_Node(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void Stack_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		Node* Current = Stack->List;
		while (Current->NextNode != NULL)
		{
			Current = Current->NextNode;
		}
		
		Current->NextNode = NewNode;
	}

	Stack->Top = NewNode;
}

Node* Stack_Pop(LinkedListStack* Stack)
{
	Node* OldTop = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node* Current = Stack->List;

		while (Current->NextNode != Stack->Top)
		{
			Current = Current->NextNode;
		}
		
		Current->NextNode = NULL;
		Stack->Top = Current;
	}

	return OldTop;
}

Node* Stack_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int GetSize(LinkedListStack* Stack)
{
	Node* Current = Stack->List;
	int Count = 0;
	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

int IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}
