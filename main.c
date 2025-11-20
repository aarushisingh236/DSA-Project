#include <stdio.h>
#include "maze.h"
#include "graph.h"

int main() {
    Maze maze;
    int rows, cols, sx, sy, sx2 = -1, sy2 = -1, ex, ey, max_steps;

    printf("Enter maze size (rows cols): ");
    scanf("%d %d", &rows, &cols);
    initMaze(&maze, rows, cols);

    printf("Enter start (x y): ");
    scanf("%d %d", &sx, &sy);

    printf("Enter end (x y): ");
    scanf("%d %d", &ex, &ey);

    printf("Enter max allowed steps: ");
    scanf("%d", &max_steps);

    int choice;
    do {
        displayMaze(&maze, sx, sy, sx2, sy2, ex, ey);

        printf("\nMenu:\n");
        printf("1. Add wall\n");
        printf("2. Remove wall\n");
        printf("3. Update cell cost\n");
        printf("4. Find shortest path\n");
        printf("5. Find shortest path (Two Starts)\n"); //in class
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2 || choice == 3) {
            int x, y, cost = 1;
            printf("Enter cell (x y): ");
            scanf("%d %d", &x, &y);
            if (choice == 1) updateCell(&maze, x, y, 1, 1);
            else if (choice == 2) updateCell(&maze, x, y, 1, 0);
            else {
                printf("Enter new cost: ");
                scanf("%d", &cost);
                updateCell(&maze, x, y, cost, 0);
            }
        } 

        else if (choice == 4) {
            int result = dijkstra(&maze, sx, sy, ex, ey, max_steps);
            printf("Shortest path cost = %d\n", result);
        }

        else if (choice == 5) {
            int sx2, sy2;
            printf("Enter second start S* (x y): ");
            scanf("%d %d", &sx2, &sy2);

            int result = dijkstraTwoStarts(&maze, sx, sy, sx2, sy2, ex, ey, max_steps);
            printf("Best path cost = %d\n", result);
        }

    } while (choice != 0);

    return 0;
}
