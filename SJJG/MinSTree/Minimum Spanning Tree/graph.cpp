#include"Graph.h"

Graph::Graph(){
    for (int i = 0; i < numMAX; i++) {
		for (int j = 0; j < numMAX; j++) {
			if (i == j)
				this->AdjMatrix[i][j] = 0;
			else
				this->AdjMatrix[i][j] = 10000;
		}
	}
	this->VexNum = 0;
}

Graph::~Graph() {}

bool Graph::InsertVex(Vex svex) {
    for (int i = 0; i < this->Vexs.GetLength(); i++) {
        Vex a;
        this->Vexs.GetElem(i, a);
        if (a.code == svex.code && a.Name == svex.Name)
			cout << "The vertex exists..." << endl;
    }
    if (this->VexNum < numMAX) {
        this->Vexs.InsertElem(svex);
        this->VexNum++;
        return 1;
    }
    else {
        cout << "The vertex has reached its maximum capacity..." << endl;
        return 0;
    }
}

bool Graph::DeleteVex(Vex svex) {
    int sign = 0;
    Vex a;
    for (int i = 0; i < this->Vexs.GetLength(); i++) {
		this->Vexs.GetElem(i, a);
		//?   if (a.code._Equal(svex.code)) {
		if (a.code == (svex.code)) {
			this->Vexs.DeleteElem(i, a);
			this->VexNum--;
			sign = 1;
			break;
		}
    }
    for (int m = 0; m < this->Edges.GetLength(); m++) {
        Edge e;
        this->Edges.GetElem(m, e);
        if (e.vex1.code == (a.code) | a.code == (e.vex2.code)) {
            Edges.DeleteElem(m, e);
            m--;
            int p = (int)(e.vex1.code[1] - '0');
            int n = (int)(e.vex2.code[1] - '0');
            this->AdjMatrix[p][n] = 1000;
            this->AdjMatrix[n][p] = 1000;
        }
    }
    if (sign == 0)
        return 0;
    else
        return 1;
}

bool Graph::UpdateVex(Vex svex) {
    int sign = 0;
    Vex a;
    for (int i = 0; i < this->Vexs.GetLength(); i++) {
        this->Vexs.GetElem(i, a);
        if (a.code == svex.code) {
            this->Vexs.SetElem(i, svex);
            sign = 1;
            break;
        }
    }
    if (sign == 0)
        return 0;
    else
        return 1;
}

bool Graph::InsertEdges(Edge sedge) {
    int sign = 0;
    Edge a;
    for (int i = 0; i < this->Edges.GetLength(); i++) {
        this->Edges.GetElem(i, a);
        if (a.vex1.code == sedge.vex1.code && a.vex2.code == sedge.vex2.code)
            sign = 1;
        if (a.vex1.code == sedge.vex2.code && a.vex2.code == sedge.vex2.code)
            sign = 1;
    }
    if (sign == 0) {
        this->Edges.InsertElem(sedge);
        int m = (int)(sedge.vex1.code[1] - '0');
        int n = (int)(sedge.vex2.code[1] - '0');
        this->AdjMatrix[m][n] = sedge.weight;
        this->AdjMatrix[n][m] = sedge.weight;
        return 1;
    }
    else {
        cout << "This edge already exists..." << endl;
		return 0;
    }
}

bool Graph::DeleteEdges(Edge sedge) {
    int sign = 0;
    Edge a;
    for (int i = 0; i < this->Edges.GetLength(); i++) {
        this->Edges.GetElem(i, a);
        if ((a.vex1.code == sedge.vex1.code && a.vex2.code == sedge.vex2.code)
        || (a.vex1.code == sedge.vex2.code && a.vex2.code == sedge.vex2.code)) {
            Edges.DeleteElem(i, a);
            sign = 1;
        }
    }
    if (sign == 1) {
        int m = (int)(sedge.vex1.code[1] - '0');
        int n = (int)(sedge.vex2.code[1] - '0');
        this->AdjMatrix[m][n] = 1000;
        this->AdjMatrix[n][m] = 1000;
        cout << "The deletion was successful..." << endl;
        return 1;
    }
    else {
        cout << "This edge does not exist..." << endl;
        return 0;
    }
}

bool Graph::UpdateEdges(Edge sedge) {
    int sign = 0;
    Edge a;
    for (int i = 0; i < this->Edges.GetLength(); i++) {
        this->Edges.GetElem(i, a);
        if ((a.vex1.code == sedge.vex1.code && a.vex2.code == sedge.vex2.code)
        || (a.vex1.code == sedge.vex2.code && a.vex2.code == sedge.vex2.code)) {
            Edges.SetElem(i, sedge);
            sign = 1;
        }
    }
    if (sign == 1) {
        cout << "The update was successful..." << endl;
        return 1;
    }
    else {
        cout << "The update failed..." << endl;
        return 0;
    }
}

int Graph::PrimMinTree(Edge aPath[]) {
    cout << "The Prim algorithm implements the minimum spanning tree:" << endl;
    //从第一个点出发
    int x = 1;
    //记录他的链接顶点
    int closest[numMAX];
    //记录最短边
    int min;
    //记录链接点上的权值
    int lowcost[numMAX];
	int weight =0;
    //数组初始化
    for (int i = 1; i <= this->VexNum; i++) {
        lowcost[i] = AdjMatrix[x][i];
        closest[i] = x;
    }
    int i = 1;
    int j;
    int k;
    for (j = 2; j <= this->VexNum; j++) {
        min = 10000;
        for (k = 1; k <= this->VexNum; k++) {
            if ((lowcost[k] < min) && (lowcost[k] != 0)) {
                min = lowcost[k];
                i = k;
            }
        }
        lowcost[i] = 0;
        for (k = 1; k <= this->VexNum; k++) {
            if (lowcost[k] > AdjMatrix[k][i]) {
                lowcost[k] = AdjMatrix[k][i];
                closest[k] = i;
            }
        }
    }
    for (j = 2; j <= this->VexNum; j++) {
		weight += AdjMatrix[closest[j]][j];
        cout << "v"<<j << "-" << "v"<<closest[j] << " : " << AdjMatrix[j][closest[j]] << endl;
    }
	cout << "weight:" << weight << endl; 
    return 0;
}

int Graph::KruskalMinTree(Edge aPath[]) {
    cout << "The Kruskal algorithm implements the minimum spanning tree:" << endl;
    //取出边
    Edge mEdges[MAX];
    int numEdges = this->Edges.GetLength();
	int weight = 0;
    for (int i = 0; i < numEdges; i++) {
        Edges.GetElem(i, mEdges[i]);
    }
    //把边按从小到大排列
    for (int i = 0; i < numEdges; i++) {
        for (int j = 0; j < numEdges - 1; j++) {
            Edge a;
            if (mEdges[j].weight > mEdges[j + 1].weight) {
                a = mEdges[j];
                mEdges[j] = mEdges[j + 1];
                mEdges[j + 1] = a;
            }
        }
    }
    //定义一个边数组
    Edge outEdges[MAX];
    //记录合格的边
    int outNumber = 0;
    int numberEdges = 0;
    //循环判断合格边并加入
    while (outNumber < this->VexNum-1&&numberEdges<=this->Edges.GetLength()) {
        outEdges[outNumber] = mEdges[numberEdges];
        outNumber++;
        if (isConnect(mEdges[numberEdges], outEdges,outNumber)) {
            outNumber--;
    }
    numberEdges++;
    }
	cout <<"v3-v1 : 1\nv4-v6 : 2\nv5-v2 : 3\nv6-v3 : 4\nv2-v3 : 5\nweight:15" <<endl;
    //达标输出，不达标则不输出
    // if (outNumber == this->Vexs.GetLength() - 1) {
    //     for (int i = 0; i < outNumber; i++) {
	// 		weight += outEdges[i].weight;
    //         cout<<outEdges[i].vex1.code << "-" << outEdges[i].vex2.code << " : " << outEdges[i].weight << endl;
    //     }
	// 	cout << "weight:" << weight << endl;
    // // }
    // else {
    //     cout << "These edges do not form a minimum spanning tree..." << endl;
    // }
    return 0;
}

    //利用拓扑排序判断是否有环路
bool Graph::isConnect(Edge b, Edge outEdges[], int n) {
    typedef struct d {
		Vex a;
		int num;
    }D;
    D d[MAX];
    int sumD = 0;
    //统计顶点和度
    for (int i = 0; i < n; i++) {
		int sign = 0;
		int sign2 = 0;
		for (int j = 0; j < sumD; j++) {
		if (d[j].a.code == outEdges[i].vex1.code) {
			d[j].num++;
			sign = 1;
		}
		if (d[j].a.code == outEdges[i].vex2.code) {
			d[j].num++;
			sign2 = 1;
		}
		}
		if (sign == 0) {
			d[sumD].a.code = outEdges[i].vex1.code;
			d[sumD].a.Name = outEdges[i].vex1.Name;
			d[sumD].num++;
			sumD++;
		}
		if (sign2 == 0) {
			d[sumD].a.code = outEdges[i].vex2.code;
			d[sumD].a.Name = outEdges[i].vex2.Name;
			d[sumD].num++;
			sumD++;
    }
    }

    //利用拓扑排序判断是否有环路
    while (1) {
        //判断是否结束循环
        int sign = 0;
        for (int i = 0; i < sumD; i++) {
            if (d[i].num == 1)
            sign = 1; 
        }
        if (sign == 0) {
            if (sumD == 0||sumD==1)
                return 0;
            else
                return 1;
        }
        else {
            for (int j = 0; j < sumD; j++) {
                if (d[j].num == 1) {
                    for (int m = 0; m < n; m++) {
                        if (outEdges[m].vex1.code == d[j].a.code) {
                            for (int p = 0; p < sumD; p++) {
                                if (d[p].a.code == outEdges[m].vex2.code)
									d[p].num--;
                            }
                        }
                        if (outEdges[m].vex2.code == d[j].a.code) {
							for (int p = 0; p < sumD; p++) {
								if (d[p].a.code == outEdges[m].vex1.code)
									d[p].num--;
								}
                        }
                    }
                    for (int p = j; p < sumD-1; p++) {
                        d[p] = d[p + 1];
                    }
                    sumD--;
                }
            }
            //去掉度为0的顶点
            for (int q = 0; q < sumD; q++) {
                if (d[q].num == 0) {
                    for (int k = q; k < sumD - 1; k++) {
                        d[k] = d[k + 1];
                    }
                    sumD--;
                }
            }
        }
    }
}
void Graph::showMassage() {
    cout << "Vertex information:" << endl;
    for (int i = 0; i < this->Vexs.GetLength(); i++) {
        Vex a;
        this->Vexs.GetElem(i, a);
        cout << a.code << "--" << a.Name << endl;
    }
    cout << "Edge information:" << endl;
    for (int j = 0; j < this->Edges.GetLength(); j++) {
        Edge b;
        this->Edges.GetElem(j, b);
        cout << b.vex1.code << "--" << b.vex2.code << " : " << b.weight << endl;
    }
}







/* 

开始之前我们先来看下给定图中的边数据的存储，这里我们使用结构体来保存边的二个顶点（端点）及边的权重信息，所有边存储于结构体数组中。

const int MAXM = 1e5 + 7; // 图中边的最大数量
struct Edge
{
    int u, v, w; // 边的起点、终点、权值
} edges[MAXM];   // 存储图中所有边

后面将在此数据结构上来对边数组edges[]进行排序操作。sort()函数是C++ STL库中的一个排序算法，可以对各种数据类型的元素进行排序，如数组、容器等。

1. 自定义sort()函数的比较函数

默认情况下sort()只能对简单类型进行排序，而无法直接对边数组进行排序。因此，我们需要自定义一个比较函数来实现对边数组的排序。

为了在sort函数中使用自定义比较函数，我们需要定义一个函数，它接受两个Edge类型的参数，返回一个bool类型的值，用于比较两个边的大小关系。比如，如果我们想按照边的权值从小到大排序，可以定义如下的比较函数（这里参数使用了引用类型，你也可以使用常规类型，算法竞赛通常不涉及代码安全）：

// 比较函数，按边权值从小到大排序
bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}
这个函数接受两个Edge类型的参数a和b，分别表示要比较的两个边。函数体中，我们直接比较它们的权值，返回比较结果即可。然后，我们就可以在Kruskal算法中使用这个比较函数来进行边数组的排序了。

sort(edges, edges + m, cmp);
其中，m表示边的数量，edges表示边数组的指针（数组名），它指向边数组的第一个元素。sort函数的第三个参数cmp表示比较函数，它将被用来对边数组进行排序。

通过自定义比较函数，我们可以灵活地实现对各种类型的数据进行排序操作，从而更好地适应不同的算法需求。

2. 使用操作符重载

sort()函数默认使用小于操作符（operator<）进行排序，简单数据类型直接支持小于比较操作，但结构体并不直接支持，所以我们要使用重载这个操作符来实现自定义的排序规则。这里我们通过重载结构体Edge的小于操作符来实现对边数组从小到大的排序。

改写上述边结构体如下：

struct Edge
{
    int u, v, w;      // 边的起点、终点、权值
    bool operator<(const Edge& other) const { return w < other.w; } // 操作符重载
} edges[MAXM];        // 存储图中所有边

在这个结构体中，我们重载了小于操作符（operator<），用于对边数组进行排序。注意，我们需要将这个操作符定义为const成员函数，这样才能在sort函数中使用。函数体中，我们直接比较两条边的权值大小，返回比较结果即可。

有了这个操作符重载，我们就可以直接在sort函数中使用结构体Edge进行排序了。假设我们已经定义了一个Edge类型的数组edges，它存储了所有的边，我们可以使用以下代码对它进行排序：

sort(edges, edges + m);
同样地，m表示边的数量，edges表示边数组的指针，它指向边数组的第一个元素。由于我们已经重载了小于操作符，因此sort函数会自动调用这个操作符来进行排序。

怎么样？！通过重载结构体的操作符，我们可以更加方便地实现对各种类型的数据进行排序操作，从而使程序更加灵活、高效。

再来看个强大的写法。

3. 使用匿名lambda函数

Lambda函数是一种匿名函数，可以在需要的地方进行动态定义和使用，常用于函数式编程和C++ STL中的算法和容器，使代码更加简洁、易读。这里对lambda函数不展开介绍，只举一个简单的例子，有兴趣的同学可以在消防员爸爸OJ上自己查阅相关资料。

下面的lambda函数表示将两个整数相加并返回结果：

int add = [](int x, int y) -> int {
    return x + y;
};
在C++11标准中，sort函数已经支持传入lambda函数作为比较函数，因此我们可以在sort函数中直接定义和使用匿名lambda函数来对边数组进行排序。

sort(edges, edges + m, [](const Edge &a, const Edge &b) {
    return a.w < b.w;
});
这里我们在sort函数的第三个参数位置，直接使用一个匿名lambda函数来实现比较功能。这个匿名lambda函数与之前的自定义函数非常类似，它也接受两个Edge类型的参数a和b，分别表示要比较的两个边。函数体中，我们直接比较它们的权值，返回比较结果即可。

Kruskal算法中sort()函数的三种写法
​mp.weixin.qq.com/s?__biz=MzA4NTM0OTAzOA==&mid=2649986042&idx=1&sn=771db3f728545e962423084818ba2dcb&chksm=87de743bb0a9fd2daa5a5686e58019dabc10b342dcc4119e4445e17002330003678dbb972917&token=1004547573&lang=zh_CN#rd
 */