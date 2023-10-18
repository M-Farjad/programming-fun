#include <iostream>
using namespace std;

class Graph
{
    int data;
};
int main()
{
}
// ##############  BFS  ########
// Mark all nodes v in V as unvisited
//     Mark source node s as visited
//     enq(Q, s) // First-in first-out queue Q
//     while (Q is not empty)
// {
//     u= deq(Q);
//     for each unvisited neighbour v of u
//     {
//         mark v as visited;
//         enq(Q, v);
//     }
// }

// #########  DFS  #############
// DFS(G, u)
// u.visited = true
// for each v E G.Adj[u]
// if v.visited == false
// DFS(G,V)
// init()
// {
//     For each u E G
//         u.visited = false For each u E G
//     DFS(G, u)
// }