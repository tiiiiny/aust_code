#include"Graph.h"
// 邻接表
// 构造，初始化?为0
ALGraph::ALGraph(){
	vexnum = 0;
    arcnum = 0;
    for (int i = 0; i < MVNum; ++i) {
        vexs[i].data = 0; // 假设顶点数据类型为整数，初始化为0
        vexs[i].firstarc = nullptr; // 初始时每个顶点的第一个边为空
    }
}

ALGraph::~ALGraph() {}



//若G中存在v,则返回该顶点在图中位置,否则返回-1
int ALGraph::LocateVex(ALGraph G, char v){
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i].data==v)
            return i;
    }
    return -1;
}



//建立邻接表存储方式的有向网
void ALGraph::CreateALGraph(ALGraph &G)
{
    /* 1.输入图中顶点总数与边的总数
    2.输入图中顶点信息
    3.输入边的信息，建立边结点，插入到相对应数组元素后的边表中（注：有向网中每条边需要插入两个边结点）。*/
    int i,j,k;
    char v1,v2;
    ArcNode *p, *q;
    int w;

    cin>>G.vexnum>>G.arcnum;
    for(i=0; i<G.vexnum; i++)
    {
        cin>>G.vexs[i].data;
        G.vexs[i].firstarc=NULL;
    }
    // 输入边的信息，建立边结点，插入到相对应数组元素后的边表中
    for (k = 0; k < G.arcnum; k++)
    {
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);

        // 创建一个边结点
        p = new ArcNode;
        p->adjvex = j;
        p->weight = w;
        p->nextarc = G.vexs[i].firstarc;
        G.vexs[i].firstarc = p;

        // 在有向图中每条边需要插入两个边结点
        q = new ArcNode;
        q->adjvex = i;
        q->weight = w;
        q->nextarc = G.vexs[j].firstarc;
        G.vexs[j].firstarc = q;
    }
}


//计算图中所有边的权值之和
int ALGraph::GetGraphWeight(ALGraph G)
{
    int sum = 0;

    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vexs[i].firstarc;
        while (p)
        {
            sum += p->weight;
            p = p->nextarc;
        }
    }

    return sum / 2; // 因为每条边在邻接表中被记录两次，所以总权值需要除以2

}
