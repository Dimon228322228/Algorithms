#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>

bool parseNumber(const std::string& str, int& num){
    try{
        num = std::stoi(str);
        return true;
    } catch (const std::invalid_argument& ex) {
        return false;
    }
}

int getTop(std::stack<int>& stack){
    if ( stack.empty() ){
        stack.push(0);
        return 0;
    } else return stack.top();
}

void toTop(std::stack<int>& stack, int n, bool isUsedInBlk){
    getTop(stack);
    if ( isUsedInBlk ) stack.pop();
    stack.push(n);
}

std::pair<std::string, std::string> parseEqual(const std::string& str){
    auto ptr = str.find('=');
    return std::pair<std::string , std::string> { str.substr(0,ptr), str.substr(ptr + 1, str.size()) };
}



int main(){
    std::unordered_map<std::string, std::stack<int>> vars;
    std::unordered_map<int, std::unordered_set<std::string>> uses_var;
    int num_blk = 0;
    std::string cur;

    while(std::getline(std::cin, cur)) {
        if (std::find(cur.begin(), cur.end(), '{') != cur.end()) {
            ++num_blk;
            continue;
        }
        if (std::find(cur.begin(), cur.end(), '}') != cur.end()) {
            auto& vec = uses_var[num_blk];
            for (const auto &i: vec) {
                vars[i].pop();
            }
            uses_var[num_blk].clear();
            --num_blk;
            continue;
        }

        auto [var1, var2] = parseEqual(cur);

        int n;
        auto &cUsesVar = uses_var[num_blk];
        bool isInBlk1 = cUsesVar.find(var1) != cUsesVar.end();

        if (parseNumber(var2, n)) {
            toTop(vars[var1], n, isInBlk1);
            if (!isInBlk1) cUsesVar.emplace(var1);
        } else {
            if ( cUsesVar.find(var2) == cUsesVar.end() && vars[var2].empty()) cUsesVar.emplace(var2);
            int k = getTop(vars[var2]);
            toTop(vars[var1], k, isInBlk1);
            std::cout << k << "\n";
            if (!isInBlk1) cUsesVar.emplace(var1);
        }
    }
    return 0;
}