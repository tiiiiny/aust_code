#define numMAX 20
#define StrMAX 100
#define MAX 1000

#include<iostream>
#include<string>
// #include"SqList.hpp"
#include<algorithm>
#include<vector>
using namespace std;

#define MVNum 20   //假设当前顶点数最多为20个
// int visited[MVNum];//用来存放当前顶点是否遍历过

//*****定义邻接矩阵****
typedef char VerTexType;
typedef int ArcType;

struct Edge {
    int Head, Tail,Weight;
};

class AMGraph
{
public:
    VerTexType vexs[MVNum]; // 点
    ArcType arcs[MVNum][MVNum]; // 二维数组，邻接矩阵
    int vexnum,arcnum; //点、边的个数

	struct{
		VerTexType adjvex;	//最小边在U中的那个顶点
		ArcType lowcost;	//最小边上的权值
	}closedge[MVNum];

public:
	AMGraph();
	~AMGraph();
	int LocateVex(AMGraph G, char v);
	int FisrtAdjVertex(AMGraph G, int v);
	int NextAdjVertex(AMGraph G, int v, int w);
	void CreateAMGraph(AMGraph &G);
	VerTexType min(const AMGraph &G);
	void MiniSpanTree_Prim(AMGraph G, VerTexType u);
	// void Sort(Edge edges[], int arcnum);
	void MiniSpanTree_Kruskal(AMGraph G);
	
};



void test02(AMGraph& G) {
	G.vexnum =4;
	G.arcnum =4;

    G.vexs[0] = 'a';
    G.vexs[1] = 'b';
    G.vexs[2] = 'c';
    G.vexs[3] = 'd';
	cout<<"get it"<<endl;

    for(int i=0; i<G.vexnum; i++)
        for(int j=0; j<G.vexnum; j++)   
            G.arcs[i][j]=0; 

    G.arcs[0][1]=1; 
    G.arcs[1][0]=1;
    G.arcs[0][2]=1;
    G.arcs[2][0]=1;
    G.arcs[1][2]=1;
    G.arcs[2][1]=1;
    G.arcs[2][3]=1;
    G.arcs[3][2]=1;

	Edge e1 = {G.vexs[0],G.vexs[1],4};
	Edge e2 = {G.vexs[0],G.vexs[2],2};
	Edge e3 = {G.vexs[2],G.vexs[1],3};
	Edge e4 = {G.vexs[2],G.vexs[3],5};


    for(int i=0; i<G.vexnum; i++){
        for(int j=0; j<G.vexnum; j++)   
            cout<<G.arcs[i][j]<<" "; 
		cout <<endl;
	}
    cin.get();


    // 测试最小生成树（Prim算法）
    cout << "Minimum Spanning Tree (Prim Algorithm):" << endl;
    G.MiniSpanTree_Prim(G, G.vexs[0]);
	cout<<endl;
    cin.get();


    // 测试最小生成树（Kruskal算法）
    cout << "Minimum Spanning Tree (Kruskal Algorithm):" << endl;
    G.MiniSpanTree_Kruskal(G);


    cin.get();
}
void test01(AMGraph* graph) {
    //输入测试数据
    // 创建邻接矩阵图
    graph->CreateAMGraph(*graph);

    // 输出图的顶点和边的个数
    cout << "Vertex Number: " << graph->vexnum << endl;
    cout << "Edge Number: " << graph->arcnum << endl;

    // 输出邻接矩阵
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < graph->vexnum; ++i) {
        for (int j = 0; j < graph->vexnum; ++j) {
            cout << graph->arcs[i][j] << " ";
        }
        cout << endl;
    }


    // 测试最小生成树（Prim算法）
    cout << "Minimum Spanning Tree (Prim Algorithm):" << endl;
    graph->MiniSpanTree_Prim(*graph, graph->vexs[0]);

    // 测试最小生成树（Kruskal算法）
    cout << "Minimum Spanning Tree (Kruskal Algorithm):" << endl;
    graph->MiniSpanTree_Kruskal(*graph);
    cin.get();
}
int main() {
    AMGraph *G = new AMGraph();
    test02(*G);
    // test01(graph);
}





// 邻接矩阵
// 构造函数、初始化
AMGraph::AMGraph() {
    vexnum = arcnum = 0; // 初始化点和边的个数为0
    // 初始化邻接矩阵，将所有边的权值置为一个较大的数（表示无穷大）
    for (int i = 0; i < MVNum; ++i) {
        for (int j = 0; j < MVNum; ++j) {
            arcs[i][j] = INT_MAX;
        }
    }
}
AMGraph::~AMGraph() {}
//若G中存在v,则返回该顶点在图中位置,否则返回-1
int AMGraph::LocateVex(AMGraph G, char v)
{
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i]==v)
            return i;
    }
    return -1;
}
//返回顶点v的第一个临接点位置,否则返回-1
int AMGraph::FisrtAdjVertex(AMGraph G, int v)
{
    int j;
    for(j=0; j<G.vexnum; j++)
        if(G.arcs[v][j]!=0)
            return j;
    return -1;
}
//返回顶点v相对于w的下一个临接点位置,否则返回-1
int AMGraph::NextAdjVertex(AMGraph G, int v, int w)
{
    int j;
    for(j=w+1; j<G.vexnum; j++)
        if(G.arcs[v][j]!=0)
            return j;
    return -1;
}
//邻接矩阵存储方式建立无向图
void AMGraph::CreateAMGraph(AMGraph &G)
{
    VerTexType v1,v2;
	cout<<"点数 边数"<<endl;
    cin>>G.vexnum>>G.arcnum;
    getchar();

    for(int i=0; i<G.vexnum; i++)
    {
		cout<<i <<":点的含义：";
        cin>>G.vexs[i];
        getchar();
    }
	cout<<"get it"<<endl;

    for(int i=0; i<G.vexnum; i++)
        for(int j=0; j<G.vexnum; j++)   
            G.arcs[i][j]=0; 

    for(int k=0; k<G.arcnum; k++)
    {
		cout<<"head tail"<<endl;
        cin>>v1>>v2;
		cin.get();
		cin.get();
		cin.get();
        int i=LocateVex(G, v1); 
        int j=LocateVex(G, v2); 
        G.arcs[i][j]=1; 
        G.arcs[j][i]=1;
        cout<<"enter以继续。。。"<<endl;
		cin.get();
		cin.get();
    }
	cout << "end"<<endl;
}
VerTexType AMGraph::min(const AMGraph &G) {
    int minIndex = -1;
    ArcType minCost = INT_MAX;
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.closedge[i].lowcost > 0 && G.closedge[i].lowcost < minCost) {
            minCost = G.closedge[i].lowcost;
            minIndex = i;
        }
    }
    return minIndex;
}
void AMGraph::MiniSpanTree_Prim(AMGraph G, VerTexType u){ 
    int k =LocateVex(G, u); 	//k为顶点u的下标 
    for(int j = 0; j < G.vexnum; ++j) 
		if(j != k){  
			G.closedge[j].adjvex = u;
			G.closedge[j].lowcost = G.arcs[k][j]; 
		}
    G.closedge[k].lowcost = 0;   //初始，U = {u}

	for(int i = 1; i < G.vexnum; ++i) { //选择其余n-1个顶点，生成n-1条边(n= G.vexnum) 
		VerTexType k = min(G);  // 求出T的下一个结点：第k个顶点，closedge[k]中存有当前最小边 
		VerTexType u0 = G.closedge[k].adjvex; //u0为最小边的一个顶点，u0∈U 
		VerTexType v0 = G.vexs[k]; //v0为最小边的另一个顶点，v0∈V-U 

		cout <<u0 <<" "<< v0<<endl; //输出当前的最小边(u0, v0) 

		G.closedge[k].lowcost = 0;  //第k个顶点并入U集 
		for(int j = 0; j < G.vexnum; ++j) 
			if(G.arcs[k][j] < closedge[j].lowcost)
			{ //新顶点并入U后重新选择最小边 
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}
	}
}
bool cmp(const Edge &a, const Edge &b)
{
    return a.Weight < b.Weight;
}
// void AMGraph::Sort(Edge edges[], int arcnum) {
//     // 排序算法，可以根据实际情况选择合适的排序方法
//     // 这里使用了C++标准库中的 sort 函数
//     sort(edges, edges + arcnum, [](const Edge &a, const Edge &b) {
//         return a.Weight < b.Weight;
//     });
// }
// kruskal
void AMGraph::MiniSpanTree_Kruskal(AMGraph G) {
	int Vexset[MVNum];
	Edge edges[G.arcnum];

	sort(edges, edges + arcnum, cmp);
    // Sort(Edge, G.arcnum); // 将数组Edge中的元素按权值从小到大排序

    for (int i = 0; i < G.vexnum; ++i)
        Vexset[i] = i;
    for (int i = 0; i < G.arcnum; ++i) {
        int v1, v2, vs1, vs2;
        v1 = LocateVex(G, edges[i].Head);
        v2 = LocateVex(G, edges[i].Tail);
        vs1 = Vexset[v1];
        vs2 = Vexset[v2];
        if (vs1 != vs2) {
            cout << edges[i].Head << " " << edges[i].Tail << " ";
            
            for (int j = 0; j < G.vexnum; ++j)
                if (Vexset[j] == vs2) Vexset[j] = vs1;
        }
    }
}
