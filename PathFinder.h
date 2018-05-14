//
// Created by Артем Чумаченко on 05.05.2018.
//

#ifndef VOYAGEUR_PATH_H
#define VOYAGEUR_PATH_H

#include "Graph.h"
#include "FlatSpace.h"
#include <algorithm>
#include <ostream>

class PathFinder {
public:
    explicit PathFinder(FlatSpace& FS);
    PathFinder(const PathFinder& graphfs) = default;
    PathFinder& operator=(const PathFinder& graphfs) = default;
    ~PathFinder() = default;

    void find_path_best();
    void find_path_approx_2();
    // TODO
    void find_path_approx_1_5();

    friend std::ostream& operator<<(std::ostream& os, const PathFinder& path);
    int& el_path(int i);
private:
    Graph graph;
    FlatSpace FS;
    Graph mst;
    std::vector<int> path;
};


#endif //VOYAGEUR_PATH_H
