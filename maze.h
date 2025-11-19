#ifndef MAZE_H
#define MAZE_H

#define MAX 50   // Maximum grid size

typedef struct {
    int cost;      // movement cost (>=1)
    int blocked;   // 1 if wall/restricted zone
} Cell;

typedef struct {
    int rows, cols;
    Cell grid[MAX][MAX];
} Maze;

// Functions
void initMaze(Maze *m, int r, int c);
void displayMaze(Maze *m, int sx, int sy, int sx2, int sy2, int ex, int ey);
void updateCell(Maze *m, int x, int y, int cost, int blocked);

#endif