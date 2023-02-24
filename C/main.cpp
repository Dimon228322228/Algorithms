#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>

int main(){
    std::map<std::string, std::stack<int>> vars; // var -> its values

    std::map<int, std::vector<std::string>> uses_var; // number of block -> list of using variables there

    int num_blk = 0; // number block

    std::string cur;

    while(std::getline(std::cin, cur)){
        if (std::find(cur.begin(), cur.end(), '{') != cur.end()) ++num_blk;
        if (std::find(cur.begin(), cur.end(), '}') != cur.end()) {
            auto vec = uses_var[num_blk];
            for (const auto & i : vec){
                vars[i].pop();
            }
            uses_var[num_blk].clear();
            --num_blk;
        }

        if (auto ptr = std::find(cur.begin(), cur.end(), '='); ptr != cur.end()) {

            // split string by left side and right side
            std::string var1 = std::string(cur.begin(), ptr),
                        var2 = std::string(ptr + 1, cur.end());

            // if not var1 in list of using vars -> add this var there
            if (std::find(uses_var[num_blk].begin(), uses_var[num_blk].end(), var1) == uses_var[num_blk].end()) {
                uses_var[num_blk].push_back(var1);
                if ( vars.find(var1) == vars.end() ) vars[var1].push(0);
            }

            if (auto v = vars.find(var2); v == vars.end()) {
                // there is no var2 in list of vars
                try {
                    vars[var1].push(std::stoi(var2));
                } catch(std::invalid_argument) {
                    vars[var2].push(0);
                    uses_var[num_blk].push_back(var2);
                    vars[var1].push(0);
                    std::cout << 0 << "\n";
                }
            } else {
                vars[var1].push(v->second.top());
                std::cout << v->second.top() << "\n";
            }
        }

    }
    return 0;
}