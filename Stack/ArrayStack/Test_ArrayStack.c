#include "ArrayStack.h"

int main()
{
	int i = 0;
	ArrayStack* Stack = NULL;

	Create_Stack(&Stack, 5);

	Stack_Push(Stack, 11);
	Stack_Push(Stack, 15);
	Stack_Push(Stack, 31);
	Stack_Push(Stack, 23);

	printf("Size : %d, Top: %d, Capacity : %d\n", GetSize(Stack), TopStack(Stack), Stack->Capacity);

	printf("Capacity Full : %d (1:FULL, 2:NOTFULL)\n", IsFull(Stack));

	for (i = 0; i < 4; i++)
	{
		if (EmptyStack(Stack))
			break;

		printf("Popped : %d, ", Stack_Pop(Stack));

		if (!EmptyStack(Stack))
			printf("CurrentTop = %d\n", TopStack(Stack));
		else
			printf("Empty\n");
	}

	Destroy(Stack);

	return 0;
}