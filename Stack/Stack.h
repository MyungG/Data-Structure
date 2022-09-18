#pragma once

#ifndef Stack_H
#define Stack_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
} Node;

//스택의 최하위와 최상위를 가리키는 노드
typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;

void Create_Stack(LinkedListStack** Stack);
void Destroy_Stack(LinkedListStack* Stack);

Node* Create_Node(char* Data);
void Destroy_Node(Node* _Node);

void Stack_Push(LinkedListStack* Stack, Node* NewNode);
Node* Stack_Pop(LinkedListStack* Stack);

Node* Stack_Top(LinkedListStack* Stack);
int GetSize(LinkedListStack* Stack);
int IsEmpty(LinkedListStack* Stack);

#endif