#include <iostream>
#include <list>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <utility>

using namespace boost;
using namespace std;

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, boost::no_property, EdgeWeightProperty> UndirectedGraph;
typedef boost::graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

void graphWeight(UndirectedGraph g);

void findMinWay();

int main() {
    UndirectedGraph g;

    boost::add_edge(0, 1, 5, g);
    boost::add_edge(0, 7, 4, g);
    boost::add_edge(7, 2, 3, g);
    boost::add_edge(7, 8, 1, g);
    boost::add_edge(2, 8, 2, g);
    boost::add_edge(8, 6, 7, g);
    boost::add_edge(8, 3, 2, g);
    boost::add_edge(6, 5, 9, g);
    boost::add_edge(5, 4, 8, g);
    boost::add_edge(3, 4, 6, g);


    std::pair<edge_iterator, edge_iterator> ei = edges(g);

    std::cout << "Number of edges = " << num_edges(g) << "\n";
    std::cout << "list of adges:\n";

    for (edge_iterator it = ei.first; it != ei.second; ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    findMinWay();
    graphWeight(g);

    return 0;
}

void graphWeight(UndirectedGraph g) {
    boost::property_map<UndirectedGraph, boost::edge_weight_t>::type EdgeWeightMap = get(boost::edge_weight_t(), g);

    std::pair<edge_iterator, edge_iterator> edgePair;
    for (edgePair = edges(g); edgePair.first != edgePair.second; ++edgePair.first) {
        std::cout << *edgePair.first << " " << EdgeWeightMap[*edgePair.first] << std::endl;
    }
}

void findMinWay() {
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_weight_t, int> > graph_t;
    typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_descriptor;
    typedef std::pair<int, int> Edge;

    const int num_nodes = 6;
    enum nodes {
        A, B, C, D, E, F
    };
    char name[] = "ABCDEF";
    Edge edge_array[] = {
            Edge(C, A),
            Edge(A, B),
            Edge(A, E),
            Edge(F, A),
            Edge(B, C),
            Edge(B, D),
            Edge(E, C),
            Edge(E, F),
            Edge(D, F),
            Edge(D, E),
            Edge(F, B)
    };

    int weights[] = {10, 7, 8, 6, 8, 12, 10, 8, 1, 13, 5};
    int num_arcs = sizeof(edge_array) / sizeof(Edge);

    graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);

    boost::property_map<graph_t, boost::edge_weight_t>::type weightmap = get(boost::edge_weight, g);

    std::vector<vertex_descriptor> p(num_vertices(g));
    std::vector<int> d(num_vertices(g));

    vertex_descriptor s = vertex(A, g);
    vertex_descriptor goal = vertex(F, g);

    boost::dijkstra_shortest_paths(g, s,boost::predecessor_map(&p[0]).distance_map(&d[0]));


    std::vector<boost::graph_traits<graph_t>::vertex_descriptor> path;
    boost::graph_traits<graph_t>::vertex_descriptor current = goal;

    while (current != s) {
        path.push_back(current);
        current = p[current];
    }
    path.push_back(s);

    std::cout << "Path from " << name[s] << " to " << name[goal] << std::endl;
    std::vector<boost::graph_traits<graph_t>::vertex_descriptor>::reverse_iterator it;

    for (it = path.rbegin(); it != path.rend(); ++it) {
        std::cout << name[*it] << " ";
    }
    std::cout << std::endl;

}