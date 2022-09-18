#pragma once

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
} Node;

typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void Create_Stack(ArrayStack** Stack, int Capacity);
void Stack_Push(ArrayStack* Stack, int Data);
int Stack_Pop(ArrayStack* Stack);
int GetSize(ArrayStack* Stack);
int EmptyStack(ArrayStack* Stack);
int TopStack(ArrayStack* Stack);
int IsFull(ArrayStack* Stack);

#endif