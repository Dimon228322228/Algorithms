#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<bool>> &canVisitedByWeight, vector<bool> &visited, int numVertices, int from, bool direction) {
    visited[from] = true;
    for (int i = 0; i < numVertices; i++)
        if ((direction ? canVisitedByWeight[i][from] : canVisitedByWeight[from][i]) && !visited[i])
            dfs(canVisitedByWeight, visited, numVertices, i, direction);
}

bool canVisitAll(vector<bool> &visited, int numVertices){
    for ( int i = 0; i < numVertices; i++ )
        if (!visited[i]) return false;
    return true;
}

int main() {
    int n, k, r = 0, l = 0, mid; cin >> n;
    int weight[n][n];
    vector<bool> visited(n, false);
    vector<vector<bool>> canVisitByWeight(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; weight[i][j] = k, j++) {
            cin >> k;
            r = max(r, k);
        }

    while( l < r ){
        mid = (r + l) / 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                canVisitByWeight[i][j] = weight[i][j] <= mid;
        fill(visited.begin(), visited.end(), false);
        dfs(canVisitByWeight, visited, n, 0, true);
        if (canVisitAll(visited, n)){
            fill(visited.begin(), visited.end(), false);
            dfs(canVisitByWeight, visited, n, 0, false);
        }
        if (canVisitAll(visited, n)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    return 0;
}