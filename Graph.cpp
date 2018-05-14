//
// Created by Артем Чумаченко on 05.05.2018.
//

#include "Graph.h"

Edge::Edge(int begin, int end, float weight): begin(begin), end(end), weight(weight) {
}

Edge::Edge(): begin(-1), end(-1), weight(0) {
}

bool operator<(const Edge &first, const Edge &second){
    return first.weight < second.weight;
}


Graph::Graph(size_t n): Vertex_to_edges(n) {
}

void Graph::add_Edge(int v1, int v2, float w) {
    Edges.emplace_back(v1, v2, w);
    Vertex_to_edges[v1].push_back(static_cast<int>(Edges.size()) - 1);
}

// Boruvka algorithm
void MST(Graph& mst, Graph& graph){
    mst = Graph(graph.v_size());
    SetOnTree scc(graph.v_size());
    std::vector<Edge> min_edges(graph.size());

    while(!scc.is_one_set()) {
        int s = scc.max_element();
        min_edges = std::vector<Edge>(s + 1, {-1, -1, std::numeric_limits<int>::max()});

        for(int i = 0; i < graph.size(); i++) {
            if(scc.find_set(graph[i].begin) != scc.find_set(graph[i].end)) {
                if(graph[i] < min_edges[scc[graph[i].begin]]) {
                    min_edges[scc[graph[i].begin]] = graph[i];
                }
                if(graph[i] < min_edges[scc[graph[i].end]]) {
                    min_edges[scc[graph[i].end]] = graph[i];
                }
            }
        }

        std::set<Edge> min_edges_wl(min_edges.begin(), min_edges.end());
        for(const Edge& i: min_edges_wl) {
            if(scc[i.begin] != scc[i.end]){
                scc.union_set(i.begin, i.end);
                mst.add_Edge(i);
            }
        }
    }
}

void Graph::add_Edge(const Edge& e) {
    Edges.push_back(e);
    Vertex_to_edges[e.begin].push_back(static_cast<int>(Edges.size()) - 1);
}

void Graph::dfs(std::vector<int> &path) const{
    std::vector<bool> is_visited(Vertex_to_edges.size(), false);
    is_visited[0] = true;
    dfs_(0, is_visited, path);
}

void Graph::dfs_(int v, std::vector<bool> &is_visited, std::vector<int> &path) const {
    path.push_back(v);
    for(auto i: Vertex_to_edges[v]) {
        if(!is_visited[Edges[i].end]) {
            is_visited[Edges[i].end] = true;
            dfs_(Edges[i].end, is_visited, path);
            path.push_back(v);
        }
    }
}

Edge &Graph::operator[](int i) {
    return Edges[i];
}

size_t Graph::size() const {
    return Edges.size();
}

size_t Graph::v_size() const {
    return Vertex_to_edges.size();
}

std::vector<int> &Graph::operator()(int i) {
    return Vertex_to_edges[i];
}

