//
// Created by Артем Чумаченко on 05.05.2018.
//

#include "PathFinder.h"

PathFinder::PathFinder(FlatSpace &FS): FS(FS), graph(FS.size()), mst(FS.size()) {
    for(int i = 0; i < FS.size(); i++) {
        for (int j = i + 1; j < FS.size(); j++) {
            graph.add_Edge(i, j, FS[i] - FS[j]);
            graph.add_Edge(j, i, FS[j] - FS[i]);
        }
    }

    MST(mst, graph);
}

void PathFinder::find_path_approx_2() {
    path.clear();
    Graph t_mst = mst;

    size_t old_t_mst_size = t_mst.size();
    for(int i = 0; i < old_t_mst_size; i++) {
        t_mst.add_Edge(t_mst[i].end, t_mst[i].begin, t_mst[i].weight);
    }

    std::vector<int> temp_path;
    t_mst.dfs(temp_path);
    for(int i: temp_path) {
        if(std::find(path.begin(), path.end(), i) == path.end()) {
            path.push_back(i);
        }
    }
}

// TODO
void PathFinder::find_path_approx_1_5() {
    path.clear();
    Graph t_mst = mst;

    std::vector<int> odd_vertex;
    for(int i = 0; i < t_mst.v_size(); i++) {
        if(t_mst(i).size() % 2 == 1) {
            odd_vertex.push_back(i);
        }
    }

    std::vector<int> must_delete_v;
    std::vector<int> temp_odd_vertex;
    std::vector<int> min_vertex(odd_vertex.size());
    std::vector<float> weight_min_vertex(odd_vertex.size(), std::numeric_limits<float>::max());
    while(min_vertex.size() > 1) {
        for(int i_1 = 0; i_1 < odd_vertex.size(); i_1++) {
            for(int i_2 = 0; i_2 < odd_vertex.size(); i_2++) {
                if(i_1 != i_2) {
                    if(weight_min_vertex[i_1] > FS[odd_vertex[i_1]] - FS[odd_vertex[i_2]]) {
                        min_vertex[i_1] = i_2;
                        weight_min_vertex[i_1] = FS[odd_vertex[i_1]] - FS[odd_vertex[i_2]];
                    }
                }
            }
        }

        for(int i = 0; i < min_vertex.size(); i++) {
            if(min_vertex[min_vertex[i]] == i) {
                t_mst.add_Edge(i, min_vertex[i], FS[odd_vertex[i]] - FS[odd_vertex[min_vertex[i]]]);
                must_delete_v.push_back(i);
            }
        }

        for(int i = 0; i < odd_vertex.size(); i++) {
            if(std::find(must_delete_v.begin(), must_delete_v.end(), i) == must_delete_v.end()) {
                temp_odd_vertex.push_back(odd_vertex[i]);
            }
        }
        odd_vertex = temp_odd_vertex;
        must_delete_v.clear();
        temp_odd_vertex.clear();
        min_vertex.assign(odd_vertex.size(), -1);
        weight_min_vertex.assign(odd_vertex.size(), std::numeric_limits<float>::max());
    }


    std::vector<int> temp_path;
    t_mst.dfs(temp_path);
    for(int i: temp_path) {
        if(std::find(path.begin(), path.end(), i) == path.end()) {
            path.push_back(i);
        }
    }
}

std::ostream &operator<<(std::ostream &os, const PathFinder &path) {
    for(auto i: path.path) {
        os<<i<<' ';
    }
    return os;
}

int &PathFinder::el_path(int i) {
    return path[i];
}

void PathFinder::find_path_best() {
    path.clear();
    std::vector<int> temp_path(this->graph.v_size());
    std::iota(temp_path.begin(), temp_path.end(), 0);
    float min_weight = std::numeric_limits<float>::max();
    float temp_min_weight = 0;
    do {
        temp_min_weight = 0;
        for (int i = 0; i < this->graph.v_size() - 1; i++) {
            temp_min_weight += FS[temp_path[i]] - FS[temp_path[i + 1]];
        }
        if (temp_min_weight < min_weight) {
            path = temp_path;
            min_weight = temp_min_weight;
        }
    } while(std::next_permutation(temp_path.begin() + 1, temp_path.end()));
}
