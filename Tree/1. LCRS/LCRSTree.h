#pragma once

#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;		// 자식 노드
	struct tagLCRSNode* RightSibling;	// 형제 노드
	ElementType			Data;			// 노드 데이타
} LCRSNode;

LCRSNode*	LCRS_CreateNode(ElementType NewData);
void		LCRS_DestroyNode(LCRSNode* Node);
void		LCRS_DestroyTree(LCRSNode* Root);

void		LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode);
void		LCRS_PrintTree(LCRSNode* Node, int Depth);
void		LCRS_PrintNode(LCRSNode* Node, int level);

void		LCRS_PrintNodesAtLevel(LCRSNode* Root, int level);
#endif