#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int numTest, n, k;
    cin >> numTest;
    for (int i = 0; i < numTest; ++i){
        cin >> n >> k;
        int comGroup = n / k, sum = 0, rest = n % k;
        sum += k * (k - 1) / 2 * pow(comGroup,2);
        for ( int j = 0; j < rest; ++j ) sum += comGroup * (k - 1) + j;
        cout << sum << "\n";
    }
    return 0;
}