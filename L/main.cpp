#include <iostream>
#include <deque>

using namespace std;

void add_back( deque<int>& line, int item){
    while( !line.empty() && line.back() > item ) line.pop_back();
    line.push_back(item);
}

int main(){
    int n, k; cin >> n >> k;
    int queue[n];
    deque<int> line;
    for ( int i = 0; i < n; i++ ) cin >> queue[i];
    for ( int i = 0; i < k; i++ ) add_back(line, queue[i]);
    cout << line[0] << " ";
    for ( int i = k; i < n; i++ ){
        if ( line[0] == queue[i - k] ) line.pop_front();
        add_back(line, queue[i]);
        cout << line[0] << " ";
    }
    return 0;
}