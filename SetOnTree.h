//
// Created by Артем Чумаченко on 05.05.2018.
//

#ifndef VOYAGEUR_BASICTYPES_H
#define VOYAGEUR_BASICTYPES_H

#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <set>

class SetOnTree {
public:
    explicit SetOnTree(size_t n);
    SetOnTree(const SetOnTree& tset) = default;
    SetOnTree& operator=(const SetOnTree& tset) = default;
    ~SetOnTree() = default;

    void union_set(int a, int b);
    int find_set(int v);
    bool is_one_set() const;
    int max_element() const;

    int&operator[](int i);
private:
    std::vector<int> scc;
    std::vector<int> size;
};


#endif //VOYAGEUR_BASICTYPES_H
