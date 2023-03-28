#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<int> weight(26);
    vector<int> amount_sym(26);
    for (int & i : weight) cin >> i;
    for (char & i : s) amount_sym[toascii(i) - 97]++;
//    for (int i = 0; i < amount_sym.size(); i++) cout <<"\n" << char(97 + i) << " " << amount_sym[i];

//    cout << toascii('a');
    return 0;
}