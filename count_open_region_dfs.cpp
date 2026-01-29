#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<vector<int>> maze;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// DFS function to calculate size of one region
int dfs(int x, int y) {
    visited[x][y] = true;
    int size = 1;

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx >= 0 && ny >= 0 && nx < R && ny < C) {
            if(maze[nx][ny] == 0 && !visited[nx][ny]) {
                size += dfs(nx, ny);
            }
        }
    }
    return size;
}

int main() {
    cin >> R >> C;

    maze.assign(R, vector<int>(C));
    visited.assign(R, vector<bool>(C, false));

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> maze[i][j];
        }
    }

    vector<int> regionSizes;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(maze[i][j] == 0 && !visited[i][j]) {
                int regionSize = dfs(i, j);
                regionSizes.push_back(regionSize);
            }
        }
    }

    cout << "Number of regions: " << regionSizes.size() << "\n";
    cout << "Region sizes: ";
    for(int sz : regionSizes) {
        cout << sz << " ";
    }
    cout << "\n";

    return 0;
}
