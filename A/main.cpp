#include <iostream>
#include <string>

int main() {
    size_t  n,
            prev,
            cur,
            max_len = 1,
            cur_len = 1,
            first_index = 0;
    int reps = 1;

    std::cin >> n >> prev;

    for (size_t i = 1; i < n; ++i){
        std::cin >> cur;
        ++cur_len;
        if (cur == prev) ++reps;
        else reps = 1;

        if (reps == 3){
            if ( max_len < cur_len - 1 ){
                max_len = cur_len - 1;
                first_index = i + 1 - cur_len;
            }
            reps = 2;
            cur_len = 2;
        }
        if ( max_len < cur_len ){
            max_len = cur_len;
            first_index = i + 1 - cur_len;
        }
        prev = cur;
    }
    std::cout << first_index + 1 << " " << first_index + max_len << "\n";
}