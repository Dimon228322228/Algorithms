#include <iostream>
#include <list>
#include <deque>

using namespace std;

void normalize( deque<int>& begin, deque<int>& end ){
    if ( begin.size() < end.size() ) {
        begin.push_back(end[0]); end.pop_front();
    }
}

void add_center( deque<int>& begin, deque<int>& end, int n ){
    end.push_front(n);
    normalize(begin, end);
}

void add_end( deque<int>& begin, deque<int>& end, int n ){
    end.push_back(n);
    normalize(begin, end);
}

void get_number( deque<int>& begin, deque<int>& end, int* num ){
    *num = begin[0];
    begin.pop_front();
    normalize(begin, end);
}

int main(){
    string str;
    int n, k, num;
    getline(cin, str); n = stoi(str);
    deque<int> begin, end;
    for ( int i = 0; i < n; i++ ){
        getline(cin, str);
        char sign = str[0];
        if (sign == '-') {
            get_number(begin, end, &k); cout << k << "\n";
            continue;
        }
        if ( str.length() > 1 ) num = stoi(str.substr(1));
        if (sign == '+') add_end(begin, end, num);
        else add_center(begin, end, num);
    }
    return 0;
}