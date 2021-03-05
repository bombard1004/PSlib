// graph.cpp
// author bombard1004
// last_update Mar 05 2021

#include <bits/stdc++.h>

template<typename T>
class SparseGraph {
    struct Node {
        std::vector<std::pair<int, T>> adj;
        T value;
    };

private:
    std::vector<Node> nodes;
    int nodeSize;
    int edgeSize = 0;

public:
    SparseGraph(int n) {
        nodes.resize(n);
        nodeSize = n;
    }

    SparseGraph(const std::vector<T> &values) {
        int n = values.size();
        nodes.resize(n);
        nodeSize = n;
        for(int i = 0; i < n; i++)
            nodes[i].value = values[i];
    }

    void addEdge(int u, int v, const T &edgeVal = 0) {
        nodes[u].adj.push_back({v, edgeVal});
        edgeSize++;
    }

    const int &getNodeSize() const {
        return nodeSize;
    }

    const int &getEdgeSize() const {
        return edgeSize;
    }

    const T &valueOf(int here) const {
        return nodes[here].value;
    }

    const std::vector<std::pair<int, T>> &adjOf(int here) const {
        return nodes[here].adj;
    }
};

template<typename T>
std::vector<T> dijkstra(const SparseGraph<T> &graph, int src) {
    using edge = std::pair<T, int>;
    constexpr auto INF = std::numeric_limits<T>::max();

    const int V = graph.getNodeSize();
    std::vector<T> dist(V, INF);

    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> edgePQ;
    dist[src] = 0; edgePQ.push(edge{0, src});

    while(!edgePQ.empty())  {
        T currDist = edgePQ.top().first; int here = edgePQ.top().second;
        edgePQ.pop();

        const auto nextVisits = graph.adjOf(here);
        for(const auto &nextvisit : nextVisits) {
            int there = nextvisit.first; T nextDist = currDist + nextvisit.second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                edgePQ.push(edge{nextDist, there});
            }
        }
    }

    return dist;
}

template<typename T>
class RootedTree {
    struct Node {
        int parent;
        std::vector<int> children;
        T value;
        int depth;
    };

private:
    std::vector<Node> nodes;
    int root = -1;
    int height = 0;

    void fillNodesInfo(int here, int parent, int depth, const SparseGraph<T> &sg) {
        nodes[here].value = sg.valueOf(here);
        nodes[here].parent = parent;
        nodes[here].depth = depth;
        for(const int &nd : sg.adjOf(here)) {
            if(nd != parent) {
                nodes[here].children.push_back(nd);
                fillNodesInfo(nd, here, depth+1, sg);
            }
        }
        if(height < depth)
            height = depth;
    }

public:
    RootedTree(const SparseGraph<T> &sg, int _root) {
        int n = sg.getNodeSize();
        int e = sg.getEdgeSize();
        if(e != n-1)
            return;
        
        root = _root;
        nodes.resize(n);
        fillNodesInfo(_root, -1, 0, sg);
    }

    int getRoot() const {
        return root;
    }

    int getHeight() const {
        return height;
    }

    int parentOf(int here) const {
        return nodes[here].parent;
    }

    const std::vector<int> &childrenOf(int here) const {
        return nodes[here].children;
    }

    T valueOf(int here) const {
        return nodes[here].value;
    }

    int depthOf(int here) const {
        return nodes[here].depth;
    }

    bool isChild(int child, int parent) const {
        return nodes[child].parent == parent;
    }

};
