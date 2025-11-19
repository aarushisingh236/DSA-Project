#include <stdio.h>
#include "graph.h"

// Min Heap Implementation

void initHeap(MinHeap *h)
{
    h->size = 0;
}

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void pushHeap(MinHeap *h, HeapNode val)
{
    int i = ++h->size;
    h->data[i] = val;

    while (i > 1 && h->data[i].dist < h->data[i/2].dist)
    {
        swap(&h->data[i], &h->data[i/2]);
        i = i / 2;
    }
}

HeapNode popHeap(MinHeap *h)
{
    HeapNode top = h->data[1];
    h->data[1] = h->data[h->size--];

    int i = 1, smallest = i;

    while (1)
    {
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= h->size && h->data[left].dist < h->data[smallest].dist)
            smallest = left;

        if (right <= h->size && h->data[right].dist < h->data[smallest].dist)
            smallest = right;

        if (smallest != i)
        {
            swap(&h->data[i], &h->data[smallest]);
            i = smallest;
        }
        else 
            break;
    }

    return top;
}

int isHeapEmpty(MinHeap *h)
{
    return h->size == 0;
}