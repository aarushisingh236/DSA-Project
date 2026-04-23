# 🧩 Dynamic Maze Shortest Path Finder

> A terminal-based pathfinding system in C that computes shortest paths on a dynamically changing grid using Dijkstra's algorithm.

---

## Overview

This project models a maze as a weighted graph and applies **Dijkstra's algorithm** to compute the shortest path between a start (`S`) and end (`E`) cell.

Unlike static implementations, the system supports **runtime modifications**, requiring the pathfinding algorithm to adapt to changes such as wall insertions/removals and movement cost updates.

---

## Features

- Grid-based maze representation
- **Dynamic updates at runtime:**
  - Add or remove walls
  - Modify movement costs per cell
- Shortest path computation from `S` to `E`
- Handles blocked and unreachable paths gracefully
- Optional step constraints on traversal
- Efficient node selection using a **Min-Heap** (priority queue)

---

## Core Design

### Grid as Graph

- Each cell represents a **node**
- Edges connect adjacent cells (4-directional movement)
- Edge weights are derived from movement cost per cell

### Data Structures

| Structure | Description |
|---|---|
| `maze[][]` | 2D grid storing wall status and movement cost |
| `dist[][]` | Distance matrix tracking shortest known distance from source |
| `visited[][]` | Visited matrix to prevent redundant processing |
| **Min-Heap** | Priority queue for efficient extraction of the closest unvisited node |

> Using a Min-Heap reduces time complexity to **O((V + E) log V)**

### Algorithm

1. Initialize all distances as **infinity**
2. Insert the start node into the min-heap with distance `0`
3. Repeatedly:
   - Extract the node with the **minimum distance**
   - **Relax** neighboring nodes if a shorter path is found
4. Continue until the destination `E` is reached or all nodes are processed

### Handling Dynamic Updates

After any modification (wall or cost change), the system **recomputes the shortest path from scratch** using Dijkstra's algorithm. This prioritizes **correctness and simplicity** over incremental update optimization.

---

## Example Interaction

```
Grid initialized:
S . . #
. # . .
. . . E

> Add wall at (0,2)
> Update cost at (2,1) = 5
> Recompute path

Shortest path cost: 12
```

---

## Getting Started

### Prerequisites

- GCC or any C compiler

### Compile

```bash
gcc main.c maze.c dijkstra.c minHeap.c -o maze
```

### Run

```bash
./maze
```

---

## Design Decisions

| Decision | Rationale |
|---|---|
| **Dijkstra over BFS** | Supports weighted paths; BFS only works for unweighted graphs |
| **Custom Min-Heap** | Improves efficiency over naive linear search for the minimum node |
| **Full recomputation on updates** | Avoids the complexity of incremental algorithms while guaranteeing correctness |

---

## Limitations

- Recomputes the entire path after each update (no incremental optimization)
- Limited to grid-based graphs — no support for arbitrary graph structures
- Terminal-based only — no graphical visualization
- Performance degrades for very large grids

---

## Future Improvements

- [ ] Implement incremental pathfinding (e.g., D* or LPA* algorithms)
- [ ] Add CLI or GUI visualization
- [ ] Support diagonal movement or more complex graph topologies
- [ ] Benchmark performance across varying grid sizes

---

## Tech Stack

- **Language:** C
- **Data Structures:** Custom Min-Heap (priority queue), 2D arrays
- **Algorithm:** Dijkstra's shortest path

---

## Project Structure

```
.
├── main.c          # Entry point and user interaction
├── maze.c          # Grid initialization and dynamic update logic
├── maze.h
├── dijkstra.c      # Shortest path computation
├── dijkstra.h
├── minHeap.c       # Priority queue implementation
├── minHeap.h
└── README.md
```
