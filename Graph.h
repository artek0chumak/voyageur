//
// Created by Артем Чумаченко on 05.05.2018.
//

#ifndef VOYAGEUR_GRAPH_H
#define VOYAGEUR_GRAPH_H

#include "SetOnTree.h"
#include <limits>

class Edge {
public:
    Edge();
    Edge(int begin, int end, float weight);
    Edge(const Edge& edge) = default;
    Edge& operator=(const Edge& edge) = default;
    ~Edge() = default;

    friend bool operator<(const Edge& first, const Edge& second);

    int begin;
    int end;
    float weight;
};

class Graph {
public:
    Graph() = default;
    explicit Graph(size_t n);
    Graph(const Graph& graph) = default;
    Graph& operator=(const Graph& graph) = default;
    ~Graph() = default;

    void add_Edge(int v1, int v2, float w);
    void add_Edge(const Edge& e);
    void dfs(std::vector<int>& path) const;

    //Edges
    size_t size() const;
    Edge& operator[](int i);
    //Vertex_to_edges
    size_t v_size() const;
    std::vector<int>& operator()(int i);

private:
    void dfs_(int v, std::vector<bool>& is_visited, std::vector<int>& path) const;
    std::vector<std::vector<int> > Vertex_to_edges;
    std::vector<Edge> Edges;
};

void MST(Graph& mst, Graph& graph);


#endif //VOYAGEUR_GRAPH_H
