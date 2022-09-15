#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
 public:
  Graph(int n) : n(n), adjacency(std::vector<std::vector<int>>::size_type(n)) {}

  void add_edge(int u, int v) {
    adjacency[u].emplace_back(v);
    adjacency[v].emplace_back(u);
  }

  vector<int> shortest_reach(int start) {
    std::vector<int> result(std::vector<int>::size_type(n), -1);
    std::vector<int> visited(std::vector<int>::size_type(n), 0);
    int distance = 0;
    std::vector<int> queue{start};
    for (int distance = 0; queue.size() > 0; distance += 6) {
      std::vector<int> next_queue;
      for (auto node : queue) {
        result[node] = distance;
        for (auto child : adjacency[node]) {
          if (result[child] != -1) {
            continue;
          }
          if (visited[child]) {
            continue;
          }
          visited[child] = 1;
          next_queue.emplace_back(child);
        }
      }
      std::swap(queue, next_queue);
      next_queue.clear();
    }
    return result;
  }

 private:
  int n;
  std::vector<std::vector<int>> adjacency;
};

int main() {
  int queries;
  cin >> queries;

  for (int t = 0; t < queries; t++) {
    int n, m;
    cin >> n;
    // Create a graph of size n where each edge weight is 6:
    Graph graph(n);
    cin >> m;
    // read and set edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      // add each edge to the graph
      graph.add_edge(u, v);
    }
    int startId;
    cin >> startId;
    startId--;
    // Find shortest reach from node s
    vector<int> distances = graph.shortest_reach(startId);

    for (int i = 0; i < distances.size(); i++) {
      if (i != startId) {
        cout << distances[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
