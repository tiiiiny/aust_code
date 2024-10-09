/*
*  1.添加顶点若重复————无报错或其他，
*  2.运行整个程序需走./main.out ！！！
*  2.运行整个程序或者./myprogram ！！！(make) ???(Makefile)
*  3.优化之处？？
*  4.测试案例数据？？
*/
/* 
	城市通信网络的线路设计（第七组）
（1）在n个城市之间建设通讯网络，建立最小生成树；				（  		）
（2）城市间的距离网采用邻接矩阵表示，也可用邻接表表示；			  （		）
（3）分别用普里姆算法和克鲁斯卡尔算法求最小生成树；				 （		☑️	）

	*prim 稠密网 邻接矩阵
	*kruscal 稀疏网 邻接表

（4）最小生成树中包括边及其权值，并显示得到的最小生成树的代价。 	（		 ）
*/

#include<iostream>
#include<string>
#include"Graph.h"
#include"SqList.hpp"
using namespace std;

void test01(Graph* graph) {
    //输入测试数据
    Vex v1; v1.code = "V1"; v1.Name = "北京";
    Vex v2; v2.code = "V2"; v2.Name = "成都";
    Vex v3; v3.code = "V3"; v3.Name = "武汉";
    Vex v4; v4.code = "V4"; v4.Name = "上海";
    Vex v5; v5.code = "V5"; v5.Name = "广州";
    Vex v6; v6.code = "V6"; v6.Name = "深圳";
    graph->InsertVex(v1);
    graph->InsertVex(v2);
    graph->InsertVex(v3);
    graph->InsertVex(v4);
    graph->InsertVex(v5);
    graph->InsertVex(v6);
    Edge e1; e1.vex1 = v1; e1.vex2 = v2; e1.weight = 6;
    Edge e2; e2.vex1 = v1; e2.vex2 = v3; e2.weight = 1;
    Edge e3; e3.vex1 = v1; e3.vex2 = v4; e3.weight = 5;
    Edge e4; e4.vex1 = v2; e4.vex2 = v3; e4.weight = 5;
    Edge e5; e5.vex1 = v2; e5.vex2 = v5; e5.weight = 3;
    Edge e6; e6.vex1 = v3; e6.vex2 = v4; e6.weight = 5;
    Edge e7; e7.vex1 = v3; e7.vex2 = v5; e7.weight = 6;
    Edge e8; e8.vex1 = v3; e8.vex2 = v6; e8.weight = 4;
    Edge e9; e9.vex1 = v4; e9.vex2 = v6; e9.weight = 2;
    Edge e10; e10.vex1 = v5; e10.vex2 = v6; e10.weight = 6;
    graph->InsertEdges(e1);
    graph->InsertEdges(e2);
    graph->InsertEdges(e3);
    graph->InsertEdges(e4);
    graph->InsertEdges(e5);
    graph->InsertEdges(e6);
    graph->InsertEdges(e7);
    graph->InsertEdges(e8);
    graph->InsertEdges(e9);
    graph->InsertEdges(e10);
    cout << "Added successfully..." << endl;
    cin.get();
}
int main() {
    Graph *graph = new Graph();
    Edge a[10];
    while (1) {
		cout << "----------------------------------------------" << endl;
        cout << "1. Test city map case" << endl;
        cout << "2. Add vertex" << endl;
        cout << "3. Add edge" << endl;
        cout << "4. Prim algorithm" << endl;
        cout << "5. Kruskal algorithm" << endl;
        cout << "6. Delete and modify information" << endl;
        cout << "7. Print vertex and edge information" << endl;
        cout << "8. Exit" << endl;
		cout << "----------------------------------------------" << endl;
		
        int select;
        cin >> select;
        switch (select) {
            case 1: {
                test01(graph);
				cin.get();
                break;
            }
            case 2: {
                cout << "Enter the number of vertices to be added: " << endl;
                int n = 0;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    Vex v;
                    cout << "Enter the vertex :" << endl;
                    cin >> v.code>> v.Name;
                    graph->InsertVex(v);
                }
				cin.get();
                break;
            }
            case 3: {
                cout << "Enter the number of edges to be added:" << endl;
                int n = 0;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    Edge e;
                    cout << "Input(vex1 vex2 weight):" << endl;
                    cin >> e.vex1.code>> e.vex2.code>> e.weight;
                    // cout << "输入另一个顶点" << endl;
                    // cin >> e.vex2.code;
                    // cout << "输入权值" << endl;
                    // cin >> e.weight;
                    graph->InsertEdges(e);
                }
				cin.get();
                break;
            }
            case 4: {
                graph->PrimMinTree(a);
                cin.get();
                break;
            }
            case 5: {
                graph->KruskalMinTree(a);
                cin.get(); 
                break;
            }
            case 6: {
                cout << "1. Modify vertex" << endl;
                cout << "2. Delete vertex" << endl;
                cout << "3. Modify edge" << endl;
                cout << "4. Delete edge" << endl;
                int select;
                cin >> select;
                if (select == 1) {
                    Vex a;
                    cout << "Enter the modified vertex number:" << endl;
                    cin >> a.code>> a.Name;
                    graph->UpdateVex(a);
                }
                else if (select == 2) {
                    Vex b;
                    cout << "Enter the modified vertex informayion:" << endl;
                    cin >> b.code;
                    graph->DeleteVex(b);
                }
                else if (select == 3) {
                    Edge c;
                    cout << "Enter the modified edge information:" << endl;
                    cin >> c.vex1.code>> c.vex2.code>> c.weight;
                    graph->UpdateEdges(c);
                }
                else if (select == 4) {
                    Edge d;
                    cout << "Enter the first vertex number of the modified edge:" << endl;
                    cin >> d.vex1.code>> d.vex2.code;
                    graph->DeleteEdges(d);
                }
                else {
                    cout << "Enter error..." << endl;
                }
                cin.get();
                break;
            }
            case 7: {
                graph->showMassage();
                cin.get();
                break;
            }
            case 8: {
                return 0;
                break;
            }
			
        }
    }
}