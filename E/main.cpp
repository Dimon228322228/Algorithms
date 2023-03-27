#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool canPlaceCows(vector<int>& pls, int k, int dist) {
    int last = pls[0], placed = 1;
    for (int i = 1; i < pls.size(); i++) {
        if (pls[i] - last >= dist) {
            last = pls[i];
            placed++;
            if (placed == k) return true;
        }
    }
    return false;
}

int findMaxDistance(vector<int>& pls, int k) {
    int l = 1,
        r = pls[pls.size() - 1] - pls[0],
        maxDist = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (canPlaceCows(pls, k, mid)) {
            maxDist = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return maxDist;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> places(n);
    for (int i = 0; i < n; i++) cin >> places[i];
    cout << findMaxDistance(places, k);
    return 0;
}