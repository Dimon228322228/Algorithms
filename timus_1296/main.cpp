#include <iostream>

using namespace std;

int main(){
    int n, cur, i;
    long minSum = 30001, curSum = 0, maxSum = 0;
    cin >> n;
    for ( i = 0; i < n; ++i ){
        cin >> cur;
        minSum = min( minSum, curSum );
        curSum += cur;
        maxSum = max( maxSum, curSum - minSum );
        if ( maxSum < 0 ) maxSum = 0;
    }
    cout << maxSum;
    return 0;
}