#include <stdio.h>
#include "maze.h"

void initMaze(Maze *m, int r, int c) {
    m->rows = r;
    m->cols = c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            m->grid[i][j].cost = 1;
            m->grid[i][j].blocked = 0;
        }
}

void displayMaze(Maze *m, int sx, int sy, int sx2, int sy2, int ex, int ey) {
    printf("\nMaze Layout:\n");

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {

            if (i == sx && j == sy)
                printf("S ");        // First start

            else if (i == sx2 && j == sy2)
                printf("S* ");      // Second start

            else if (i == ex && j == ey)
                printf("E ");       // End

            else if (m->grid[i][j].blocked)
                printf("# ");

            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void updateCell(Maze *m, int x, int y, int cost, int blocked) {
    if (x < 0 || y < 0 || x >= m->rows || y >= m->cols) return;
    m->grid[x][y].cost = cost;
    m->grid[x][y].blocked = blocked;
}
