#include <iostream>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> maze(R, vector<int>(C));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> maze[i][j];
        }
    }

    // If start or end is blocked
    if(maze[0][0] == 1 || maze[R-1][C-1] == 1) {
        cout << "Minimum steps: -1\n";
        return 0;
    }

    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int,int>> q;

    // Start BFS
    q.push({0, 0});
    dist[0][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx >= 0 && ny >= 0 && nx < R && ny < C) {
            if(maze[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}


    cout << "Minimum steps: " << dist[R-1][C-1] << "\n";
    return 0;
}



