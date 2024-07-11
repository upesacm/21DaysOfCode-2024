# Questions for Day 20 – (07/10/2024)
## DSA:
**Question 1:** 
Given an undirected graph, determine if it is possible to color the vertices of the graph using at most 2 colors such that no two adjacent vertices share the same color.
##### Inputs:
- The number of vertices and edges in the graph.
- A list of edges.
##### Output:
- "YES" if the graph can be colored using 2 colors, otherwise "NO".
##### Example:
#### Graph:
```
  1 -- 2
  |    |
  3 -- 4
```
#### Vertices: 4
#### Edges: [(1, 2), (1, 3), (2, 4), (3, 4)]
#### Output: YES
<br>

**Question 2:** 
Implement Dijkstra's algorithm to find the shortest path from a starting node to all other nodes in a weighted graph.
##### Inputs:
- The number of vertices and edges in the graph.
- A list of edges with their weights.
- The starting node.
##### Output:
- The shortest path distance to each node from the starting node.
##### Example:
#### Graph:
```
  1 --(4)-- 2
  |        / |
 (1)     (2) |
  |   (3)    |
  3 -------- 4
```
#### Vertices: 4
#### Edges: [(1, 2, 4), (1, 3, 1), (2, 4, 2), (3, 4, 3)]
#### Start: 1
#### Output: [0, 4, 1, 4]
<br>

## WEB-DEV:
Today, we will continue working on SQL queries to manipulate and retrieve data from the employees and departments tables.

### Tasks:
1. Write a SQL query to retrieve the names of employees and their corresponding department names.
2. Write a SQL query to calculate the total number of employees in each department.
3. Write a SQL query to retrieve the names of employees who have a salary greater than the average salary of the employees in their department.
4. Write a SQL query to delete all employees who belong to the 'Marketing' department from the employees table.

Submit all the queries performed in a .txt file.
