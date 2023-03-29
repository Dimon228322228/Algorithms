#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s; cin >> s;
    vector<int> amount_sym(26);
    vector<pair<int, size_t>> ch_w(26);
    for (char i : s) amount_sym[i - 'a']++;
    for (int i = 0; i < 26; i++){
        size_t n; cin >> n; ch_w[i] = {i, n};
    }

    sort(ch_w.begin(), ch_w.end(), [](auto & n1, auto & n2){return n1.second > n2.second;});

    string res(s.size(), ' '); size_t beg = 0, end = s.size() - 1;
    for (int i = 0; i < 26; i++ )
        if ( amount_sym[ch_w[i].first] > 1 ) {
            res[beg] = char(ch_w[i].first + 97); beg++;
            res[end] = char(ch_w[i].first + 97); end --;
        }
    for ( int i = 0; i < 26; i++ )
        for (size_t j = 0; j < (amount_sym[i] > 1 ? amount_sym[i] - 2 : amount_sym[i]); j++){
            res[beg] = char(i + 97); beg++;
        }
    cout << res;
    return 0;
}