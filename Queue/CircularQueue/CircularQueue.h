#pragma once

#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
} Node;

typedef struct tagCircularQueue
{
	int Capacity;
	int Rear;
	int Front;
	Node* Nodes;
} CircualrQueue;

void Create_Queue(CircualrQueue** Queue, int Capacity);
void Destory_Queue(CircualrQueue* Queue);

void Enqueue(CircualrQueue* Queue, int Data);
int Dequeue(CircualrQueue* Queue);

int GetSize(CircualrQueue* Queue);
int IsEmpty(CircualrQueue* Queue);
int IsFull(CircualrQueue* Queue);

#endif
