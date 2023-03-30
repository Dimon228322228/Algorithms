#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k, sum = 0; cin >> k;
    vector<pair<int, int>> amt_sign(k);
    int n_i;
    for ( int i = 0; i < k; i++ ){
        cin >> n_i; sum += n_i;
        amt_sign[i] = {i + 1, n_i};
    }
    int lm = -1;
    while ( sum > 0 ){
        int max = 0, ci;
        for ( int i = 0; i < k; i++ ){
            if ( lm != i && amt_sign[i].second > max){
                max = amt_sign[i].second; ci = i;
            }
        }
        lm = ci;
        cout << amt_sign[lm].first << " ";
        sum--; amt_sign[lm].second--;
    }
    return 0;
}