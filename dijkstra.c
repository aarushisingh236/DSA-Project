#include <stdio.h>
#include <limits.h>
#include "graph.h"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dijkstra(Maze *m, int sx, int sy, int ex, int ey, int max_steps)
{
    int dist[MAX][MAX];
    int visited[MAX][MAX] = {0};

    // Initialize distances
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            dist[i][j] = INT_MAX;
    
    MinHeap h;
    initHeap(&h);

    dist[sx][sy] = 0;

    HeapNode tempstart;
    tempstart.x = sx;
    tempstart.y = sy;
    tempstart.dist = 0;

    pushHeap(&h, tempstart);

    while (!isHeapEmpty(&h))
    {
        HeapNode cur = popHeap(&h);
        int x = cur.x, y = cur.y;

        if (visited[x][y]) 
            continue;
        visited[x][y] = 1;

        // Goal reached
        if (x == ex && y == ey)
        {
            printf("Shortest Path Cost: %d\n", dist[x][y]);
            return dist[x][y];
        }

        // Explore neighbors
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= m->rows || ny >= m->cols)
                continue;

            if (m->grid[nx][ny].blocked)
                continue;

            int newDist = dist[x][y] + m->grid[nx][ny].cost;

            if (newDist < dist[nx][ny] && newDist <= max_steps)
            {
                dist[nx][ny] = newDist;

                HeapNode tempdist;
                tempdist.x = nx;
                tempdist.y = ny;
                tempdist.dist = newDist;

                pushHeap(&h, tempdist);
            }
        }
    }

    printf("No feasible path found.\n");
    return -1;
}

int dijkstraTwoStarts(Maze *m, int sx1, int sy1, int sx2, int sy2, int ex, int ey, int max_steps)
{
    int cost1 = dijkstra(m, sx1, sy1, ex, ey, max_steps);
    int cost2 = dijkstra(m, sx2, sy2, ex, ey, max_steps);

    printf("\nCost from Start S (%d,%d) = %d\n", sx1, sy1, cost1);
    printf("Cost from Start S* (%d,%d) = %d\n", sx2, sy2, cost2);

    if (cost1 == -1 && cost2 == -1) {
        printf("No feasible path from either start!\n");
        return -1;
    }

    if (cost2 == -1 || (cost1 != -1 && cost1 <= cost2)) {
        printf("\n>>> Shortest path is from S\n");
        return cost1;
    }

    printf("\n>>> Shortest path is from S*\n");
    return cost2;
}