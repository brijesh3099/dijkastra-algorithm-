# Internet and Higher Layer Protocol Project - dijkastra-algorithm

This project implements a solution for finding the shortest path in a graph using Dijkstra's algorithm. The implementation is tailored for use in Internet and higher layer protocol development.

## Overview

The project consists of a C program that computes the shortest path from a given source vertex to all other vertices in a weighted graph. The graph represents network nodes, and the edges represent the connections between them, with weights indicating the cost or distance between nodes.

## Features

- **Dijkstra's Algorithm**: The program employs Dijkstra's algorithm to find the shortest path from a given source vertex to all other vertices in the graph.
- **Graph Representation**: The graph is represented using an adjacency matrix, allowing efficient traversal and path computation.
- **Dynamic Memory Allocation**: Memory is dynamically allocated for the graph and auxiliary data structures, ensuring flexibility and efficient memory usage.
- **Command-Line Interface**: The program is executed from the command line, taking input parameters such as the size of the graph and the source vertex.

## Usage

To use the program, follow these steps:

1. Clone the repository to your local machine.
2. Compile the C program using a C compiler (e.g., gcc).
3. Execute the compiled program from the command line, providing input parameters as necessary.

Example usage:

```
$ gcc -o shortest_path shortest_path.c
$ ./shortest_path
```

## Input

The program takes input in the form of a weighted graph, represented as an adjacency matrix. Each cell in the matrix represents the weight of the edge between two vertices. The source vertex for computing the shortest path is also provided as input.

## Output

Upon execution, the program computes the shortest path from the given source vertex to all other vertices in the graph. It outputs the distance from the source vertex to each destination vertex.
