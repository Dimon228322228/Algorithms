#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell {
    int x, y, time;
    string path;
    Cell(int x, int y, int time, string path) : x(x), y(y), time(time), path(path) {}
};

bool isValid(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

pair<int, string> findPath(vector<vector<char>>& map, int startX, int startY, int endX, int endY) {
    int N = map.size(), M = map[0].size();

    vector<vector<Cell>> visited(N, vector<Cell>(M, {-1, -1, -1, ""}));
    vector<vector<int>> time(N, vector<int>(M, -1));

    queue<Cell> q;

    Cell startCell(startX, startY, 0, "");
    q.push(startCell);
    visited[startX][startY] = startCell;
    time[startX][startY] = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    char directions[] = {'N', 'E', 'S', 'W'};

    while (!q.empty()) {
        Cell currCell = q.front();
        q.pop();

        int currX = currCell.x;
        int currY = currCell.y;
        int currTime = currCell.time;
        string currPath = currCell.path;

        if (currX == endX && currY == endY) break;

        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (isValid(newX, newY, N, M) && map[newX][newY] != '#') {
                int newTime = currTime + (map[newX][newY] == 'W' ? 2 : 1);
                if ( visited[newX][newY].time == -1 || visited[newX][newY].time > newTime ){
                    string newPath = currPath;
                    newPath += directions[i];
                    Cell newCell(newX, newY, newTime, newPath);
                    q.push(newCell);
                    visited[newX][newY] = newCell;
                    time[newX][newY] = newTime;
                }
            }
        }
    }
    return make_pair(visited[endX][endY].time, visited[endX][endY].path);
}

int main() {
    int N, M; // Размеры карты мира
    int startX, startY; // Координаты начального положения поселенца
    int endX, endY; // Координаты клетки, куда нужно привести поселенца

    cin >> N >> M >> startX >> startY >> endX >> endY;

    vector<vector<char>> map(N, vector<char>(M));

    // Считываем карту мира
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    // Находим минимальное время и путь
    pair<int, string> result = findPath(map, startX - 1, startY - 1, endX - 1, endY - 1);

    // Выводим результат
    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}