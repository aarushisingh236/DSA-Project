#ifndef GRAPH_H
#define GRAPH_H

#include "maze.h"

typedef struct {
    int x, y;
    int dist;
} HeapNode;

typedef struct {
    HeapNode data[2500];
    int size;
} MinHeap;

void initHeap(MinHeap *h);
void pushHeap(MinHeap *h, HeapNode val);
HeapNode popHeap(MinHeap *h);
int isHeapEmpty(MinHeap *h);

int dijkstra(Maze *m, int sx, int sy, int ex, int ey, int max_steps);

#endif