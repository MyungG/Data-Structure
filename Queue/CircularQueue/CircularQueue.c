#include "CircularQueue.h"

void Create_Queue(CircualrQueue** Queue, int Capacity)
{
	(*Queue) = (CircualrQueue*)malloc(sizeof(CircualrQueue));

	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1)); // 마지막 노드는 비워두기위해

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void Destory_Queue(CircualrQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void Enqueue(CircualrQueue* Queue, int Data)
{
	int Position;

	if (Queue->Rear == Queue->Capacity)
	{
		Position = Queue->Rear;
		Queue->Rear = 0; // 마지막 노드는 비워둠
	}
	else
		Position = Queue->Rear++;

	Queue->Nodes[Position].Data = Data;
}

int Dequeue(CircualrQueue* Queue)
{
	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Queue->Nodes[Position].Data;
}

int GetSize(CircualrQueue* Queue)
{
	if (Queue->Rear >= Queue->Front)
		return (Queue->Rear - Queue->Front);
	else
		return (Queue->Capacity - Queue->Front) + Queue->Rear + 1;
}

int IsEmpty(CircualrQueue* Queue)
{
	return (Queue->Rear == Queue->Front);
}

int IsFull(CircualrQueue* Queue)
{
	if (Queue->Rear > Queue->Front)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	else
		return (Queue->Rear + 1) == Queue->Front;

}
