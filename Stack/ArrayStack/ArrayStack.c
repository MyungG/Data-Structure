#include "ArrayStack.h"

void Create_Stack(ArrayStack** Stack, int Capacity)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void Stack_Push(ArrayStack* Stack, int Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

int Stack_Pop(ArrayStack* Stack)
{
	int Position = --(Stack->Top);

	return Stack->Nodes[Position].Data;
}

int GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

int EmptyStack(ArrayStack* Stack)
{
	return (Stack->Top == 0);
}

int TopStack(ArrayStack* Stack)
{
	int Position = (Stack->Top)-1;

	return Stack->Nodes[Position].Data;
}

void Destroy(ArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

int IsFull(ArrayStack* Stack)
{
	int Comp = Stack->Top;

	return(Comp >= Stack->Capacity);
}