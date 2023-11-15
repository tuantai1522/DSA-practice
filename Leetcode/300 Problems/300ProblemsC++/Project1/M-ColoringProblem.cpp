// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, bool graph[101][101], int color[101],
            int currentColor, int n)
{
  // checking if the connected nodes to v have same colour as c.
  for (int i = 0; i < n; i++)
    if (graph[node][i] == 1 && currentColor == color[i])
      return false;

  // returning true if no connected node has same colour.
  return true;
}

bool graphColoringUtil(bool graph[101][101], int m,
                       int color[101], int node, int n)
{
  // if all vertices have been assigned colour then we return true.
  if (node == n)
    return true;

  for (int c = 1; c <= m; c++)
  {
    // checking if this colour can be given to a particular node.
    if (isSafe(node, graph, color, c, n))
    {
      // assigning colour to the node.
      color[node] = c;

      // calling function recursively and checking if other nodes
      // can be assigned other colours.
      if (graphColoringUtil(graph, m, color, node + 1, n) == true)
        // returning true if the current allocation was successful.
        return true;

      // if not true, we backtrack and remove the colour for that node.
      color[node] = 0;
    }
  }
  // if no colour can be assigned, we return false.
  return false;
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n)
{
  int color[101];

  // checking if colours can be assigned.
  if (graphColoringUtil(graph, m, color, 0, n) == false)
  {
    return false;
  }

  return true;
}