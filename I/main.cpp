#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, k, p, am_actions = 0;
    cin >> n >> k >> p;
    vector<int> line(p), ncar(p, 100'0000), lcar(n, -1);
    for (int i = 0; i < p; i++) cin >> line[i];
    for ( int i = 0; i < p; i++ ){
        if (lcar[line[i] - 1] >= 0) ncar[lcar[line[i] - 1]] = i;
        lcar[line[i] - 1] = i;
    }
    set<int> curcars;

    for ( int i = 0; i < p; i++ ){
        if ( !curcars.count(i) ){
            am_actions++;
            if ( curcars.size() == k ) curcars.erase(--curcars.end());
        } else curcars.erase(i);
        curcars.insert(ncar[i]);
    }

    cout << am_actions << endl;
    return 0;
}