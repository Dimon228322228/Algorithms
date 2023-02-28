#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool parseNumber(const string& str, int& num){
    try{
        num = stoi(str);
        return true;
    } catch (const invalid_argument& ex) {
        return false;
    }
}

int getTop(stack<int>& stack){
    if ( stack.empty() ){
        stack.push(0);
        return 0;
    } else return stack.top();
}

void toTop(stack<int>& stack, int n, bool isUsedInBlk){
    getTop(stack);
    if ( isUsedInBlk ) stack.pop();
    stack.push(n);
}

pair<string, string> parseEqual(const string& str){
    auto ptr = str.find('=');
    return pair<string, string> { str.substr(0,ptr), str.substr(ptr + 1, str.size()) };
}



int main(){
    unordered_map<string, stack<int>> vars;
    unordered_map<int, unordered_set<string>> uses_var;
    int num_blk = 0;
    string cur;

    while(getline(cin, cur)) {
        if (find(cur.begin(), cur.end(), '{') != cur.end()) {
            ++num_blk;
            continue;
        }
        if (find(cur.begin(), cur.end(), '}') != cur.end()) {
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
            cout << k << "\n";
            if (!isInBlk1) cUsesVar.emplace(var1);
        }
    }
    return 0;
}