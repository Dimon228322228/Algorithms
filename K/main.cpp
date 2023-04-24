#include <iostream>
#include <map>
using namespace std;

void rm(multimap<int, int>& blkBySz, map<int, int>& blks, const multimap<int, int>::iterator& it){
    blks.erase(it->second);
    blkBySz.erase(it);
}
void rmBySz(multimap<int, int>& blkBySz, map<int, int>& blks,const map<int, int>::iterator& it){
    auto it_d = blkBySz.find(it->second);
    while (it_d->second != it->first) it_d++;
    blkBySz.erase(it_d);
    blks.erase(it);
}
void ins(multimap<int, int>& blkBySz, map<int, int>& blks,const pair<int, int>& pair){
    blks.insert(pair);
    blkBySz.insert({pair.second, pair.first});
}

int main() {
    int n, m, k, index, size; cin >> n >> m;
    multimap<int, int> blkBySz; map<int, int> blks;
    pair<int, int> hist[m];
    ins(blkBySz, blks, {1, n});
    for (int i = 0; i < m; i++){
        cin >> k;
        if (k > 0) {
            auto it = blkBySz.lower_bound(k);
            if (it == blkBySz.end()) index = -1;
            else {
                index = it->second, size = it->first - k;
                rm(blkBySz, blks, it);
                if (size > 0) ins(blkBySz, blks, {index + k, size});
            }
            cout << index << endl;
            hist[i] = {k, index};
            continue;
        }
        int index_x = hist[-1 - k].second, size_x = hist[-1 - k].first;
        if (index_x == -1) continue;

        auto rBlk = blks.lower_bound(index_x);
        auto lBlk = (rBlk != blks.begin()) ? prev(rBlk) : blks.end();

        if (rBlk != blks.end() && rBlk->first == index_x + size_x){
            if (lBlk != blks.end() && index_x == lBlk->first + lBlk->second) {
                index = lBlk->first, size = lBlk->second + rBlk->second;
                rmBySz(blkBySz, blks, lBlk);
                rmBySz(blkBySz, blks, rBlk);
                ins(blkBySz, blks, {index, size + size_x});
            } else {
                size = rBlk->second;
                rmBySz(blkBySz, blks, rBlk);
                ins(blkBySz, blks, {index_x, size + size_x});
            }
        } else {
            if (lBlk != blks.end() && index_x == lBlk->first + lBlk->second) {
                index = lBlk->first, size = lBlk->second;
                rmBySz(blkBySz, blks, lBlk);
                ins(blkBySz, blks, {index, size + size_x});
            } else ins(blkBySz, blks, {index_x, size_x});
        }
        index = 0;
        hist[i] = {k, index};
    }
    return 0;
}