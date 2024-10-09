#pragma once
#ifndef __GRAPH_H__
#define __GRAPH_H__
#endif
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



#define MaxInt 32767 //代表无穷大
typedef char VerTexType; //结点数据类型


//******定义邻接表******
typedef struct ArcNode{ //边结点
    int adjvex; //邻接点在数组中的位置
    struct ArcNode *nextarc; //指向下一个边结点的指针
    int weight; //边的权重(>0)
}ArcNode;

typedef struct VNode{ //表头结点
    VerTexType data;
    ArcNode *firstarc;
}VNode, AdjList[MVNum];

class ALGraph{ //邻接表
public:
    AdjList vexs; 
    int vexnum,arcnum;
public:
	ALGraph();
	~ALGraph();
	int LocateVex(ALGraph G, char v);
	void CreateALGraph(ALGraph &G);
	int GetGraphWeight(ALGraph G);
};
