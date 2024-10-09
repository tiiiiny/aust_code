#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxInt = 32767;
const int MVNum = 100;

typedef int Status;
typedef int Boolean;
typedef char TElemType;
typedef char VerTexType;
typedef int ArcType;

struct Edge {
    VerTexType Head;
    VerTexType Tail;
    ArcType lowcost;
};

typedef struct {
    VerTexType adjvex;
    ArcType lowcost;
} Closedge[MVNum];

typedef struct {
    VerTexType vex[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

int LocateVex(AMGraph& G, VerTexType u) {
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (u == G.vex[i])
            return i;
    return -1;
}

void CreatUDN(AMGraph& G) {
    cout << "Enter the number of vexs and edges: ";
    cin >> G.vexnum >> G.arcnum;

    cout << "Enter vexs: ";
    for (int i = 0; i < G.vexnum; i++)
        cin >> G.vex[i];

    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MaxInt;
    }

    Edge edge[MVNum];
    for (int k = 0; k < G.arcnum; k++) {
        int i, j;
        char v1, v2;
        int c;
		cout << "Enter edges (src dest weight):" <<endl;
        cin >> v1 >> v2 >> c;
        edge[k].Head = v1;
        edge[k].Tail = v2;
        edge[k].lowcost = c;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = G.arcs[j][i] = c;
    }
}

int Min(Closedge SZ, AMGraph G) {
    int i = 0, j, k, min;
    while (!SZ[i].lowcost)
        i++;
    min = SZ[i].lowcost;
    k = i;
    for (j = i + 1; j < G.vexnum; j++) {
        if (SZ[j].lowcost > 0) {
            if (min > SZ[j].lowcost) {
                min = SZ[j].lowcost;
                k = j;
            }
        }
    }
    return k;
}

void prim(AMGraph G, VerTexType u) {
    int num = 0;
    Closedge closedge;
    int k = LocateVex(G, u);

    for (int j = 0; j < G.vexnum; j++) {
        closedge[j].adjvex = u;
        closedge[j].lowcost = G.arcs[k][j];
    }
    closedge[k].lowcost = 0;

    cout << "Prim's Minimum Spanning Tree:" << endl;
    for (int i = 1; i < G.vexnum; i++) {
        k = Min(closedge, G);
        cout << closedge[k].adjvex << " " << G.vex[k] << " " << closedge[k].lowcost << endl;
        num += closedge[k].lowcost;
        closedge[k].lowcost = 0;
        for (int j = 0; j < G.vexnum; j++) {
            if (G.arcs[k][j] < closedge[j].lowcost) {
                closedge[j].adjvex = G.vex[k];
                closedge[j].lowcost = G.arcs[k][j];
            }
        }
    }
    cout << "weights:" << num << endl;
}

int Vexset[MVNum];

void kruskal(AMGraph G) {
    int v1, v2, vs1, vs2, num = 0;
	Edge edge[MVNum];
	
    for (int i = 0; i < G.arcnum; i++) {
        for (int j = 0; j < G.arcnum - 1 - i; j++) {
            if (edge[j].lowcost > edge[j + 1].lowcost) {
                edge[G.arcnum + 2] = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = edge[G.arcnum + 2];
            }
        }
    }

    for (int i = 0; i < G.vexnum; i++) {
        Vexset[i] = i;
    }

    cout << "Kruskal's Minimum Spanning Tree:" << endl;
    for (int i = 0; i < G.arcnum; i++) {
        v1 = LocateVex(G, edge[i].Head);
        v2 = LocateVex(G, edge[i].Tail);
        vs1 = Vexset[v1];
        vs2 = Vexset[v2];

        if (vs1 != vs2) {
            cout << edge[i].Head << " " << edge[i].Tail << " " << edge[i].lowcost << endl;
            num += edge[i].lowcost;
            for (int j = 0; j < G.vexnum; j++) {
                if (Vexset[j] == vs2)
                    Vexset[j] = vs1;
            }
        }
    }
    cout << "weights:" << num << endl;
}

int main() {
    AMGraph G;
    CreatUDN(G);
    prim(G, G.vex[0]);
    kruskal(G);
    return 0;
}
