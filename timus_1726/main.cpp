#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned long long sum = 0; size_t k; cin >> k;
    vector<int> xs(k), ys(k);
    for (int i = 0; i < k; i++){
        cin >> xs[i] >> ys[i];
    }
    sort(xs.rbegin(), xs.rend());
    sort(ys.rbegin(), ys.rend());
    for (size_t i = 0; i < k - 1; i++)
        sum += (xs[i] - xs[i+1] + ys[i] - ys[i+1]) * (i + 1) * ( k - i - 1 );
    cout << sum / (k * (k - 1) / 2);
    return 0;
}