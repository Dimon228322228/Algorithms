#include <iostream>
#include <vector>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

void dfs(vector<int>* graph, vector<int>& visited, int node, int* nums, bool* isPossible) {
    visited[node] = GRAY;
    for (int neighbor : graph[node])
        if (visited[neighbor] == WHITE) {
            nums[neighbor] = nums[node] + 1;
            dfs(graph, visited, neighbor, nums, isPossible);
        } else if (visited[neighbor] == GRAY)
            if ( (nums[neighbor] - nums[node]) % 2 == 0 ) *isPossible = false;
    visited[node] = BLACK;
}

int main() {
    int n, m; cin >> n >> m;
    bool isPossible = true;
    vector<int> graph[n];
    int nums[n];
    vector<int> visited(n, WHITE);

    for (int i = 0; i < m; i++) {
        int l1, l2; cin >> l1 >> l2;
        graph[l1 - 1].push_back(l2 - 1);
        graph[l2 - 1].push_back(l1 - 1);
    }

    for (int i = 0; i < n; i++)
        if (visited[i] == WHITE) {
            nums[i] = i;
            dfs(graph, visited, i, nums, &isPossible);
        }
    isPossible ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}