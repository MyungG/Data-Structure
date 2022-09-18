#include "CircularQueue.h"

int main()
{
	int i;
	CircualrQueue* Queue;

	Create_Queue(&Queue, 10);

	for (i = 0; i < 4; i++)
	{
		Enqueue(Queue, i + 1);
	}

	for (i = 0; i<3; i++)
	{
		printf("Dequeue: %d, ", Dequeue(Queue));
		printf("Front:%d, Rear:%d\n", Queue->Front, Queue->Rear);
	}

	i = 100;
	while (IsFull(Queue) == 0)
	{
		Enqueue(Queue, i++);
	}

	printf("Capacity: %d, Size: %d\n\n", Queue->Capacity, GetSize(Queue));

	while (IsEmpty(Queue) == 0)
	{
		printf("Dequeue: %d, ", Dequeue(Queue));
		printf("Front:%d, Rear:%d\n", Queue->Front, Queue->Rear);
	}

	Destory_Queue(Queue);
	return 0;
}