#include "LinkedList.h"

int main()
{
	int i;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	for (i = 0; i < 5; i++)
	{
		NewNode = CreatNode(i);
		AppendNode(&List, NewNode);
	}

	PrintLinkedList(List);
	printf("\n");

	//InsertNewHead
	NewNode = CreatNode(3000);
	InsertNewHead(&List, NewNode);

	PrintLinkedList(List);
	printf("\n");

	//InsertNodeBefore
	NewNode = CreatNode(3000);
	Current = GetNode(List, 3);
	InsertNodeBefore(&List, Current, NewNode);

	PrintLinkedList(List);
	printf("\n");

	//RemoveNode
	Current = GetNode(List, 4);
	RemoveNode(&List, Current);

	PrintLinkedList(List);
	printf("\n");

	//DestroyNode
	/*
	Count = CountNode(List);
	
	for (i = 0; i < Count; i++)
	{
		Current = GetNode(List, 0);
		
		RemoveNode(&List, Current);
		DestroyNode(Current);
	}
	*/

	printf("Destroy\n");

	DestroyAllNodes(&List);

	printf("Bye\n");
	return 0;
}