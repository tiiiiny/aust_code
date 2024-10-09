/*
*  1.添加顶点若重复————无报错或其他，
*  2.运行整个程序需走./main.out ！！！
*  2.运行整个程序或者./myprogram ！！！(make) ???(Makefile)
*  3.优化之处？？
*  4.测试案例数据？？
*/
/* 
	城市通信网络的线路设计（第七组）
（1）在n个城市之间建设通讯网络，建立最小生成树；				（  	d	）
（2）城市间的距离网采用邻接矩阵表示，也可用邻接表表示；			  （	d）
（3）分别用普里姆算法和克鲁斯卡尔算法求最小生成树；				 （		d	）

	*prim 稠密网 邻接矩阵
	*kruscal 稀疏网 邻接表

（4）最小生成树中包括边及其权值，并显示得到的最小生成树的代价。 	（	d	 ）
*/

#include<iostream>
#include<string>
#include"Graph.h"
#include"SqList.hpp"
using namespace std;

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
    AMGraph *graph = new AMGraph();
    // Edge a[10];
    // while (1) {
    //     cin.get();
    //     cout << "1.测试案例" << endl;
    //     cout << "2.添加顶点" << endl;
    //     cout << "3.添加边" << endl;
    //     cout << "4.prim算法" << endl;
    //     cout << "5.kruskal算法" << endl;
    //     cout << "6.删除修改信息" << endl;
    //     cout << "7.打印顶点和边的信息" << endl;
    //     cout << "8.退出" << endl;
    //     int select;
    //     cin >> select;
    //     switch (select) {
    //         case 1: {
                test01(graph);
    //             break;
    //         }
    //         case 2: {
    //             break;
    //         }
    //         case 3: {
    //             break;
    //         }
    //         case 4: {
    //             cin.get();
    //             break;
    //         }
    //         case 5: {
    //             cin.get(); 
    //             break;
    //         }
    //         case 6: {
    //             cin.get();
    //             break;
    //         }
    //         case 7: {
    //             cin.get();
    //             break;
    //         }
    //         case 8: {
    //             return 0;
    //             break;
    //         }
			
    //     }
    // }
}