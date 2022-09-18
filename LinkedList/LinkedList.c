#include "LinkedList.h"

Node* CreatNode(ElementType Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = Data;
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void DestroyNode(Node* Node)
{
	free(Node);
}

int CountNode(Node* Head)
{
	Node* Current = Head;
	int Count = 0;

	while(Current != NULL )
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

Node* GetNode(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

void AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = *Head;
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

void InsertNodeAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

//특정 노드 앞에 새로운 노드를 삽입
void InsertNodeBefore(Node** Head, Node* Current, Node* NewNode)
{
	if ((*Head) == Current)
	{
		NewNode->NextNode = Current;
		Current = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != Current)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->NextNode = Current;
	}
}

void InsertNewHead(Node** Head, Node* NewHead)
{
	if ((*Head) == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void PrintLinkedList(Node* Head)
{
	int i;
	int Count = 0;
	Node* List = NULL;
	Count = CountNode(Head);
	
	for (i = 0; i < Count; i++)
	{
		List = GetNode(Head, i);
		printf("List[%d] : %d\n", i, List->Data);
	}
}

/* 더블 링크드 리스트에서 ...
void PrintReverse(Node* Head)
{
	Node* Current = Head;
	int i;
	int count = 0;

	count = CountNode(Head);

	for (i = count-1; i >= 0; i--)
	{
		Current = GetNode(Current, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
}
*/

void RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		(*Head) = Remove->NextNode;
	}
	else
	{
		Node* Temp = (*Head);
		while (Temp->NextNode != Remove)
		{
			Temp = Temp->NextNode;
		}

		Temp->NextNode = Remove->NextNode;
	}
}

/* Solution_1 */
void DestroyAllNodes(Node** List)
{
	if (*List == NULL)
	{
		free(List);
	}
	else
	{
		Node* Current = (*List);
		Node* Remove = NULL;
		while (Current != NULL)
		{
			Remove = Current;
			Current = Current->NextNode;
			free(Remove);
		}
	}
}

/* Solution2
void DestroyAllNodes(Node** List)
{
	if (*List == NULL)
	{
		free(List);
	}
	else
	{
		Node* Current = (*List);
		Node* Next = Current->NextNode;
		while (Next != NULL)
		{
			free(Current);
			Current = Next;
			Next = Next->NextNode;
		}
		free(Current);
	}
}
*/