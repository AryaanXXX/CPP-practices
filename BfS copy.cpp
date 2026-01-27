//BFS USES FIFO QUEUE
#include <iostream>             
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>> &graph) {
    // 1. Initialize visited array and queue
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    // 2. Setup the starting node
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        // 3. Take the front node from the queue
        int node = q.front();
        q.pop();

        // 4. Process the node (print it)
        cout << node << " ";

        // 5. Explore all neighbors
        for (int x : graph[node]) {
            // FIXED: Standard way to check if a node has NOT been visited
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    // Adjacency List representing the graph
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 connects to 1, 2
        {0, 3, 4}, // Node 1 connects to 0, 3, 4
        {0, 4},    // Node 2 connects to 0, 4
        {1, 5},    // Node 3 connects to 1, 5
        {1, 2, 5}, // Node 4 connects to 1, 2, 5
        {3, 4}     // Node 5 connects to 3, 4
    };

    cout << "BFS Traversal starting from node 0:" << endl;
    bfs(0, graph);
    cout << endl;
    
    return 0;
}



// need explantion of this code 



