#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

// 정점 구조체
typedef struct tagVertex
{
	ElementType Data;
	int Visited;
	int Index;
	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
}Vertex;

// 간선 구조체
typedef struct tagEdge
{
	int Weight;
	struct tagEdge* Next;
	Vertex* From;
	Vertex* Target;

}Edge;

// 그래프 구조체
typedef struct tagGraph
{
	Vertex* Vertices;
	int VertexCount;
}Graph;

Graph* CreateGraph();
void DestroyGraph(Graph* G);

Vertex* CreateVertex(ElementType Data);
void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);

#endif