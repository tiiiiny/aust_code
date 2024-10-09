#pragma once
#define numMAX 20
#define StrMAX 100
#define MAX 1000
#include<iostream>
#include<string>
#include"SqList.hpp"
#include<vector>
using namespace std;

//节点结构体
struct Vex {
    string code;
    string Name;
};
//边结构体
struct Edge {
    Vex vex1;
    Vex vex2;
    int weight=-1;
};

//图 类
class Graph {
private:
    int AdjMatrix[numMAX][numMAX];
    SqList<Vex>Vexs;
    SqList<Edge>Edges;
    int VexNum;
	
public:
    Graph();
    ~Graph();
    bool InsertVex(Vex svex);
    bool DeleteVex(Vex svex);
    bool UpdateVex(Vex svex);
    bool InsertEdges(Edge sedge);
    bool DeleteEdges(Edge sedge);
    bool UpdateEdges(Edge sedge);
    Edge GetEdge(char* vex1Code, char* vex2Code);
    Vex GetVex(char*vex1Code);
    void SetVexNum(int);

    int PrimMinTree(Edge aPath[]);
    int KruskalMinTree(Edge aPath[]);

    void showMassage();
private:
    bool isConnect(Edge b,Edge outEdges[],int n);
};