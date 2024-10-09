#include <iostream>
using namespace std;

#define MVNum 20   //假设当前顶点数最多为20个
int visited[MVNum];//用来存放当前顶点是否遍历过

//*****定义邻接矩阵****
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
    VerTexType vexs[MVNum]; // 点
    ArcType arcs[MVNum][MVNum]; // 二维数组，邻接矩阵
    int vexnum,arcnum; //点、边的个数
}AMGraph;

//输出图的邻接矩阵
void PrintAMGraph(AMGraph MG){
    int i,j;
    if(MG.vexnum<=0)
        return;

    for(i=0; i<MG.vexnum; i++)
        cout<<MG.vexs[i];
    cout<<endl;

    for(i=0; i<MG.vexnum; i++){
        for(j=0; j<MG.vexnum; j++)
            cout<<MG.arcs[i][j];
        cout<<endl;
    } 
}

//若G中存在v,则返回该顶点在图中位置,否则返回-1
int LocateVex(AMGraph G, char v)
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
int FisrtAdjVertex(AMGraph G, int v)
{
    //--------补充代码--Start------
    int j;
    for(j=0; j<G.vexnum; j++)
        if(G.arcs[v][j]!=0)
            return j;
    return -1;
    //--------补充代码--End-------
}

//返回顶点v相对于w的下一个临接点位置,否则返回-1
int NextAdjVertex(AMGraph G, int v, int w)
{
    //--------补充代码--Start------
    int j;
    for(j=w+1; j<G.vexnum; j++)
        if(G.arcs[v][j]!=0)
            return j;
    return -1;
    //--------补充代码--End-------
}

//邻接矩阵存储方式建立无向图
void CreateAMGraph(AMGraph &G)
{
    //--------补充代码--Start------
    int i,j,k;
    VerTexType v1,v2; 
    cin>>G.vexnum>>G.arcnum;
    getchar();

    for(i=0; i<G.vexnum; i++)
    {
        cin>>G.vexs[i];
        getchar();
    }

    for(i=0; i<G.vexnum; i++)
        for(j=0; j<G.vexnum; j++)   
            G.arcs[i][j]=0; 

    for(k=0; k<G.arcnum; k++)
    {
        cin>>v1>>v2;
        i=LocateVex(G, v1); 
        j=LocateVex(G, v2); 
        G.arcs[i][j]=1; 
        G.arcs[j][i]=1;
        getchar();
    }
//--------补充代码--End-------
}

//从第i个顶点开始深度遍历
void DFSAMGraph(AMGraph G,int i)
{ 
    //--------补充代码--Start------
    int w;
    cout<<G.vexs[i];
    visited[i]=1; 
    for(w=FisrtAdjVertex(G,i); w>=0; w=NextAdjVertex(G,i,w))
    {
        if(!visited[w])
        DFSAMGraph(G,w);
    }
    //--------补充代码--End-------
}
//从第i个顶点开始广度遍历
void BFSAMGraph(AMGraph G,int i)
{
    //--------补充代码--Start------
    int Queue[MVNum];
    int front=0,rear=0,j=0;
    cout<<G.vexs[i];
    visited[i]=1; 
    Queue[rear]=i;
    rear++;
    while(front<rear)
    {
        i=Queue[front]; 
        front++;
        for(j=0; j<G.vexnum; j++)
        {
            if((G.arcs[i][j]==1) && (!visited[j]))
            {
            cout<<G.vexs[j];  
            visited[j]=1; 
            Queue[rear]=j;
            rear++; 
            }
        }
    }
//--------补充代码--End-------
}
/*
4 4
a b c d
a b
a c
b c
c d
*/
//主函数
int main()
{
    int i,select,vex;
    char start;
    AMGraph MG;
    MG.vexnum=MG.arcnum=0;

    while(cin>>select)
    {
        if(select==1){//输出图
            PrintAMGraph(MG);
        }
        else if(select==2){//建立无向图
            CreateAMGraph(MG);
        }
        else if(select==3){//深度遍历
            getchar();
            cin>>start;//遍历的起始顶点
            vex = LocateVex(MG, start);
            for(i=0; i<MG.vexnum; i++)
                visited[i] = 0;
            DFSAMGraph(MG,vex);
            cout<<endl;
        }
        else if(select==4){//广度遍历
            getchar();
            cin>>start;//遍历的起始顶点
            vex = LocateVex(MG, start);
            for(i=0; i<MG.vexnum; i++)
                visited[i] = 0;
            BFSAMGraph(MG,vex);
            cout<<endl;
        }
    }
    return 0;
}

