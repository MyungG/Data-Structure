#include "LinkedQueue.h"

int main()
{
	Node* Popped;
	LinkedQueue* Queue;

	CreateQueue(&Queue);

	Enqueue(Queue, CreateNode("abc"));
	Enqueue(Queue, CreateNode("def"));
	Enqueue(Queue, CreateNode("efg"));
	Enqueue(Queue, CreateNode("hij"));

	printf("Queue Size : %d\n", Queue->Count);

	while (IsEmpty(Queue) == 0)
	{
		Popped = Dequeue(Queue);
		printf("Dequeue : %s \n", Popped->Data);
		DestroyNode(Popped);
	}
	DestroyQueue(Queue);

	return 0;
}