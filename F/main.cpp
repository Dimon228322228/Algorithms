#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> s(100);
    string n;
    while (cin >> n){
        if ( n.empty() ) break;
        s.push_back(n);
    }
    sort( s.begin(), s.end(), []( const string& s1, const string& s2 ){return s1 + s2 > s2 + s1;});
    for (const auto & i : s) cout << i;
    return 0;
}