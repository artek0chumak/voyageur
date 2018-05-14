//
// Created by Артем Чумаченко on 05.05.2018.
//

#include "SetOnTree.h"

SetOnTree::SetOnTree(size_t n): scc(n), size(n) {
    std::iota(scc.begin(), scc.end(), 0);
}

void SetOnTree::union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(size[a] < size[b]) {
            std::swap(a, b);
        }
        scc[b] = a;
        if(size[a] == size[b]) {
            size[a]++;
        }
    }
}

int SetOnTree::find_set(int v) {
    if(v == scc[v]) {
        return v;
    }
    return scc[v] = find_set(scc[v]);
}

bool SetOnTree::is_one_set() const {
    bool res = true;
    int example = scc[0];
    for(auto i : scc) {
        res = res & (i == example);
        if(!res) {
            return false;
        }
    }
    return res;
}

int SetOnTree::max_element() const {
    return *std::max_element(scc.begin(), scc.end());
}

int &SetOnTree::operator[](int i) {
    return scc[i];
}