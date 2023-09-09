#include <iostream>
#include <vector>
#define WHITE 0
#define GRAY 1
#define BLACK 2


using namespace std;

void dfs(vector<int>* graph, vector<int>& visited, int node, int * minBreaks) {
    visited[node] = GRAY;
    for (int neighbor : graph[node])
        if (visited[neighbor] == WHITE) dfs(graph, visited, neighbor, minBreaks);
        else if (visited[neighbor] == GRAY) (*minBreaks)++;
    visited[node] = BLACK;
}

int main() {
    int n, key, minBreaks = 0; cin >> n;
    vector<int> graph[n];
    vector<int> visited(n, WHITE);

    for (int i = 0; i < n; graph[--key].push_back(i), i++) cin >> key;

    for (int i = 0; i < n; i++)
        if (visited[i] == WHITE) dfs(graph, visited, i, &minBreaks);
    cout << minBreaks << endl;
    return 0;
}