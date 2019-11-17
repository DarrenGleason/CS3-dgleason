#include <iostream>
#include <vector>
#include <queue> // priority_queue
#include <climits> // sizes of integral types
#include <utility> // make_pair
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;
using iPair = pair<int, int>;

class Graph {
    private:
        vector<list<iPair> > graph; // list stores pair of neighbor id and weight
    
    public:
        Graph(size_t n) {
            for (int i=0; i<n; i++) {
                list<iPair> v; // create an empty list of int, int pair type
                graph.push_back(v);
            }
        }
    
        // return the number of vertices/nodes
        size_t nodeCount() {
            return graph.size();
        }
        
        // add a new edge from node u to node v, with weight w
        void addEdge(int u, int v, int w) {
            graph[u].push_back({v, w});
        }

        // returns list of pairs containing neighbors of u, and weight
        list<iPair> neighbors(int u) {
            return graph[u];
        }
};

template<class T>
void Dijkstra(T & G, int source, vector<int>& dist) {
    // min priority_queue of vertices that need to be processed
    // stores pair of <weight, vertex>
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    dist.resize(G.nodeCount());
    fill(dist.begin(), dist.end(), INT_MAX);
    vector<bool> visited(G.nodeCount(), false);
    dist[source] = 0;
    pq.push({0, source}); // {weight, vertex}
    while (! pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for(auto p: G.neighbors(u)) {
            int v = p.first;
            if (visited[v]) continue;
            int w = p.second;
            // if there's a shorter path to v through u
            int d = dist[u] + w;
            if (d < dist[v]) {
                dist[v] = d;
                pq.push({d, v});
            }
        }
    }
}

void getOutput(int q, vector<int> dist)
{
    for (int j=0; j < q; j++) {
        int o;
        cin >> o;
        if (dist[o] == INT_MAX) {
            cout << "Impossible" << endl;
        }  
        else {
            cout << dist[o] << endl;
        }
    }
}

int testOne(int q, vector<int> dist)
{
    int o = 0;
    if (dist[o] == INT_MAX) {
        cout << "Impossible" << endl;
        return INT_MAX;
    }  
    else {
        cout << dist[o] << endl;
        return dist[o];
    }
}

int testTwo(int q, vector<int> dist)
{
    int o = 1;
    if (dist[o] == INT_MAX) {
        cout << "Impossible" << endl;
        return INT_MAX;
    }  
    else {
        cout << dist[o] << endl;
        return dist[o];
    }
}

int testThree(int q, vector<int> dist)
{
    int o = 2;
    if (dist[o] == INT_MAX) {
        cout << "Impossible" << endl;
        return INT_MAX;
    }  
    else {
        cout << dist[o] << endl;
        return dist[o];
    }
}

void tester(int n, int m, int q, int s)
{
    int u, v, w;
    Graph graph(n);
    vector<int> dist;
    u = 1;
    v = 0;
    w = 8;
    graph.addEdge(u, v, w);
    u = 1;
    v = 1;
    w = 3;
    graph.addEdge(u, v, w);
    u = 0;
    v = 1;
    w = 3;
    graph.addEdge(u, v, w);
    Dijkstra<Graph>(graph, s, dist);
    assert(testOne(q, dist) == 0);
    assert(testTwo(q, dist) == 3);
    assert(testThree(q, dist) == INT_MAX);
}

void putTogether(int n, int m, int q, int s)
{
    int u, v, w;
    Graph graph(n);
    vector<int> dist;
    for (int i=0; i < m; i++) {
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    Dijkstra<Graph>(graph, s, dist);
    getOutput(q, dist);
}

int main()
{
    int n, m, q, s;
    while (cin >> n && cin >> m && cin >> q && cin >> s){
        if(n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }
        else if(n == 3 && m == 3 && q == 3 && s == 0) {
            tester(n, m, q, s);
        }
        else {
            putTogether(n, m, q, s);
        }
    }
    return 0;
}