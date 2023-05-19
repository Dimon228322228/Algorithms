#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell {
    int coord, time, prev;
    char dir;
    Cell(int coord, int time, int prev, char dir) : coord(coord), time(time), prev(prev), dir(dir) {}
};
bool operator < (const Cell &c1, const Cell &c2){ return c1.time > c2.time; }
bool isValid(int x, int y, int N, int M) { return (x >= 0 && x < N && y >= 0 && y < M); }

Cell findPath(vector<vector<char>>& map, vector<Cell>& visited, int sX, int sY, int eX, int eY) {
    int N = map.size(), M = map[0].size();
    priority_queue<Cell> q;
    Cell startCell(sX * M + sY, 0, -1, ' ');
    q.push(startCell);
    visited[sX * M + sY] = startCell;
    int dx[] = {-1, 0, 1, 0},
        dy[] = {0, 1, 0, -1};
    char directions[] = {'N', 'E', 'S', 'W'};

    while (!q.empty()) {
        Cell currCell = q.top(); q.pop();
        int currX = currCell.coord / M, currY = currCell.coord % M, currTime = currCell.time;
        if (currX == eX && currY == eY) break;

        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i], newY = currY + dy[i];
            if (isValid(newX, newY, N, M) && map[newX][newY] != '#') {
                int newTime = currTime + (map[newX][newY] == 'W' ? 2 : 1), newCoord = newX * M + newY;
                if ( visited[newCoord].time == -1 || visited[newCoord].time > newTime ){
                    Cell newCell(newCoord, newTime, currCell.coord, directions[i]);
                    q.push(newCell);
                    visited[newCoord] = newCell;
                }
            }
        }
    }
    return visited[eX * M + eY];
}

int main() {
    size_t N, M; int startX, startY, endX, endY;
    cin >> N >> M >> startX >> startY >> endX >> endY;
    vector<vector<char>> map(N, vector<char>(M));
    vector<Cell> visited(N * M, {-1, -1, -1, ' '});
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    Cell result = findPath(map, visited, startX - 1, startY - 1, endX - 1, endY - 1);
    cout << result.time << endl;
    string path;
    while ( result.prev != -1 ){
        path = result.dir + path;
        result = visited[result.prev];
    }
    cout << path << endl;
    return 0;
}