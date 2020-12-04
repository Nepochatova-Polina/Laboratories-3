#include <iostream>
#include <list>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <utility>
using namespace boost;
using namespace std;

int main(int, char *[]) {
    // тип графа
    typedef adjacency_list<vecS, vecS, directedS,
            property<vertex_color_t, default_color_type> > Graph;
    // дескриптор вершин
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    // контейнер для цепочки вершин
    typedef vector<Vertex> container;
    // тип представления дуг графа
    typedef pair<size_t, size_t> Pair;

    // Дуги графа
    Pair edges[6] = {Pair(0, 1), Pair(2, 4),
                     Pair(2, 5),
                     Pair(0, 3), Pair(1, 4),
                     Pair(4, 3)};
    // Граф
    Graph G(edges, edges + 6, 6);
    // словарь для получения номеров вершин по дескриптору вершин
    property_map<Graph, vertex_index_t>::type id = get(vertex_index, G);
    // контейнер для хранения отсортированных вершин
    container c;

    // выполнение алгоритма
    topological_sort(G, std::back_inserter(c));

    // Вывод результата: перебор дескрипторов графа в контейнере,
    // получение порядковых номеров вершин
    cout << "Топологическая проверка: ";
    for (auto ii = c.rbegin(); ii != c.rend(); ++ii)
        cout << id[*ii] << " ";
    cout << endl;

    return 0;
}