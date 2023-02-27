#include <iostream>
#include <map>
// (1 ≤ a, b ≤ 1000,
//  0 ≤ c ≤ 1000,
//  1 ≤ d ≤ 1000,
//  a ≤ d,
//  1 ≤ k ≤ 10^18)
int main(){
    std::map<   int,          int> state;
    //          ^^^           ^^^
    // number of bacterias    day

    int a, // bacterias in begin of day
        b, // a -> a*b - incubator
        c, // c kills every day
        d; // capacity container
    long k; // number of days
    std::cin >> a >> b >> c >> d >> k;

    int z = std::min(static_cast<long>(1001), k);

    for(int i = 1; i <= z; ++i){
        a = a * b - c;
        if ( a <= 0 ) {
            std::cout << 0;
            return 0;
        }
        if ( a > d ) a = d;
        if ( state[a] != 0 ){
            long period = i - state[a];
            state[a] = i;
            long offset = (k - i) % period;
            for ( auto j: state){
                if (j.second == i - offset){
                    std::cout << j.first;
                    return 0;
                }
            }
            return 0;
        } else {
            state[a] = i;
        }
    }
    std::cout << a;

    return 0;
}