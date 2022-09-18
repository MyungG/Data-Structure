#include "LinkedQueue.h"

void CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void DestroyQueue(LinkedQueue* Queue)
{
	free(Queue);
}

Node* CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}

Node* Dequeue(LinkedQueue* Queue)
{
	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}
	Queue->Count--;

	return Front;
}

int IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}
