#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 边的数据结构
struct Edge {
    int src, dest, weight;
};

// 图的数据结构
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// 邻接矩阵的类
class AdjMatrix {
private:
    int V; // 结点数量
    vector<vector<int> > matrix; // 邻接矩阵

public:
    // 构造函数，初始化邻接矩阵
    AdjMatrix(int vertices) : V(vertices) {
        matrix.resize(V, vector<int>(V, 0)); // 初始化为0，表示无连接
    }

    // 添加边
    void addEdge(int src, int dest, int weight) {
        // 在邻接矩阵中，src到dest的边权重为weight
        matrix[src][dest] = weight;
        matrix[dest][src] = weight; // 如果是无向图，需要对称地设置
    }

    // 显示邻接矩阵
    void displayMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // 获取结点数量
    int getVertexCount() const {
        return V;
    }

    // 获取边的权重
    int getWeight(int src, int dest) const {
        return matrix[src][dest];
    }
};


// 并查集的数据结构和操作
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                if (rank[rootX] == rank[rootY]) {
                    rank[rootY]++;
                }
            }
        }
    }
};

// 普里姆算法
void primMST(Graph& graph) {
    vector<int> parent(graph.V, -1);
    vector<int> key(graph.V, INT_MAX);
    vector<bool> inMST(graph.V, false);

    key[0] = 0;

    for (int count = 0; count < graph.V - 1; count++) {
        int u = -1;
        for (int v = 0; v < graph.V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (const auto& edge : graph.edges) {
            if (edge.src == u && !inMST[edge.dest] && edge.weight < key[edge.dest]) {
                parent[edge.dest] = u;
                key[edge.dest] = edge.weight;
            }
        }
    }

    // 显示最小生成树
    cout << "Prim's Minimum Spanning Tree:\n";
    for (int i = 1; i < graph.V; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
    }
}

// 克鲁斯卡尔算法
void kruskalMST(Graph& graph) {


	// 按权值排序
	for (int i = 0; i < graph.V; i++) {
        for (int j = 0; j < graph.V; j++) {
            graph.edges[i * graph.V + j].weight = graph.edges[i * graph.V + j].weight;
        }
    }
    // sort(graph.edges.begin(), graph.edges.end(), [](const Edge& a, const Edge& b) {
    //     return a.weight < b.weight;
    // }

    DisjointSet ds(graph.V);

    // 显示最小生成树
    cout << "Kruskal's Minimum Spanning Tree:\n";
    for (const auto& edge : graph.edges) {
        int rootX = ds.find(edge.src);
        int rootY = ds.find(edge.dest);

        if (rootX != rootY) {
            cout << "Edge: " << edge.src << " - " << edge.dest << " Weight: " << edge.weight << endl;
            ds.merge(rootX, rootY);
        }
    }
}

int main() {
    Graph graph;
    
    // 输入城市数量和边的数量
    cout << "Enter the number of cities: ";
    cin >> graph.V;
		cin.get();
		cin.get();
    
    cout << "Enter the number of edges: ";
    cin >> graph.E;
		cin.get();
		cin.get();
    
    // 输入边的信息
    cout << "Enter edges (src dest weight):\n";
		cin.get();
		cin.get();
    graph.edges.resize(graph.E);
    for (int i = 0; i < graph.E; i++) {
		cin.get();
        cin >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;
		cin.get();
    }

    // 调用普里姆算法和克鲁斯卡尔算法
    primMST(graph);
    kruskalMST(graph);

    return 0;
}
