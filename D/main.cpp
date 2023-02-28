#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> state;
    int a, b, c, d;
    long k;
    cin >> a >> b >> c >> d >> k;
    int z = 1000 > k ? static_cast<int>(k) : 1000;

    for(int i = 1; i <= z; ++i){
        a = a * b - c;
        if ( a <= 0 ) {
            cout << 0;
            return 0;
        }
        if ( a > d ) a = d;
        if ( state[a] != 0 ){
            long offset = (k - i) % (i - state[a]);
            state[a] = i;
            for ( auto j: state)
                if (j.second == i - offset) cout << j.first;
            return 0;
        }
        state[a] = i;
    }
    cout << a;
    return 0;
}