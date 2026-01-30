#  Dynamic Maze Shortest Path Finder

A terminal-based C program that computes the **shortest path in a dynamically changing maze** using **Dijkstra’s Algorithm**.  
Users can add/remove walls, update movement costs, and recompute the optimal path in real time.

This project demonstrates strong use of:
- Graph algorithms
- Data structures (Min-Heap / Priority Queue)
- Dynamic updates
- Modular C programming

---

##  Features

-  Maze represented as a 2D grid
-  Add or remove walls dynamically
-  Update movement cost of any cell
-  Finds shortest path from Start (S) to End (E)
-  Handles blocked/restricted cells
-  Supports maximum step constraints
-  Efficient implementation using Min-Heap (Priority Queue)

---

##  Data Structures Used

- **2D Array (Maze Grid)**  
  Stores cost and wall information for each cell

- **Min-Heap (Priority Queue)**  
  Used for efficient selection of minimum distance node in Dijkstra’s algorithm

- **Distance Matrix (`dist[][]`)**  
  Stores shortest known distance to each cell

- **Visited Matrix (`visited[][]`)**  
  Prevents redundant processing

---

##  Algorithm

The program uses **Dijkstra’s Shortest Path Algorithm** on a weighted grid:

1. Initialize distances from the start cell
2. Push start cell into Min-Heap
3. Repeatedly extract the cell with minimum cost
4. Update neighbors if shorter path is found
5. Recompute path after any dynamic maze update

---

## How to Run
### Compile the program:
gcc main.c maze.c dijkstra.c minHeap.c -o maze
### Run:
./maze

