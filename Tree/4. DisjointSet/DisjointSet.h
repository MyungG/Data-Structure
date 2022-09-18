#pragma once

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjointSet
{
	struct tagDisjointSet*	Parent;
	void*					Data;
}DisjointSet;

void			DS_UnionSet(DisjointSet* set1, DisjointSet* Set2);
DisjointSet*	DS_FindSet(DisjointSet* Set);
DisjointSet*	DS_MaskSet(void* NewData);
void			DS_DestroySet(DisjointSet* Set);

#endif