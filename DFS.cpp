#include <iostream>
#include <vector>
using namespace std;

// The recursive DFS function
void dfs(int current, vector<vector<int>> &graph, vector<bool> &visited) {
    // 1. Mark the current node as visited
    visited[current] = true;
    
    // 2. Print the node
    cout << current << " ";

    // 3. Visit all neighbors of the current node
    for (int x : graph[current]) {
        // 4. If neighbor x hasn't been visited, recurse into it
        if (!visited[x]) {
            dfs(x, graph, visited);
        }
    }
}

// Helper function to initialize the visited array
void startdfs(int start, vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    dfs(start, graph, visited);
}

int main() {
    // Corrected graph initialization using curly braces
    vector<vector<int>> graph = {
        {1, 2},    // Node 0
        {0, 3, 4}, // Node 1
        {0, 4},    // Node 2
        {1, 5},    // Node 3
        {1, 2, 5}, // Node 4
        {3, 4}     // Node 5
    };

    cout << "DFS Traversal starting from node 0:" << endl;
    startdfs(0, graph);
    cout << endl;

    return 0;
}




// Explanation of the code:

