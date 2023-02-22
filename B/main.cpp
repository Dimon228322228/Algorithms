#include <string>
#include <iostream>
#include <vector>
#include <stack>

int main(){
    std::stack<std::pair<char, int>> st;
    int num_tr = 0;
    std::string in;

    getline(std::cin, in);

    std::vector<int> cpl(in.size() / 2);
    for (int i = 0; i < in.size(); ++i){

        if (std::isupper(in[i])){

            if (!st.empty() && st.top().first == tolower(in[i])){
                cpl[num_tr] = st.top().second;
                ++num_tr;
                st.pop();
            } else st.emplace(in[i], ++num_tr);

        } else {
            if (!st.empty() && st.top().first == toupper(in[i])){
                auto item = st.top();
                cpl[item.second - 1] = i - num_tr + 1;
                st.pop();
            } else st.emplace(in[i], i - num_tr + 1);
        }
    }

    if (st.empty()) {
        std::cout << "Possible\n";
        for (int i = 0; i < cpl.size() - 1; ++i){
            std::cout << cpl[i] << " ";
        }
        std::cout << cpl[cpl.size() - 1];
    }
    else std::cout << "Impossible";
    return 0;
}