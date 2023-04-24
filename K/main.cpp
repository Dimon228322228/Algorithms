#include <iostream>

using namespace std;

struct Node{
    Node *prev, *next;
    bool free_m; int sz;

    Node(Node *prev, Node *next, bool free_m, int sz){
        this->prev = prev;
        this->next = next;
        this->free_m = free_m;
        this->sz = sz;
        if (prev) prev->next = this;
        if (next) next->prev = this;
    };

    void remove(){
        if (prev) prev->next = next;
        if (next) next->prev = prev;
    };
};

int main(){
    int n, m; cin >> n >> m;
    
    return 0;
}