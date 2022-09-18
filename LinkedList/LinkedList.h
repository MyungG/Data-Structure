#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

Node* CreatNode(ElementType Data);
Node* GetNode(Node* Head, int Location);
void DestroyNode(Node* Node);
void AppendNode(Node** Head, Node* NewNode);
void InsertNodeAfter(Node* Head, Node* NewNode);
void InsertNodeBefore(Node** Head, Node* Current, Node* NewNode);
void InsertNewHead(Node** Head, Node* NewHead);
void PrintLinkedList(Node* Head);
// void PrintReverse(Node* Head);
void RemoveNode(Node** Head, Node* Remove);
int CountNode(Node* Head);
void DestroyAllNodes(Node** List);

#endif