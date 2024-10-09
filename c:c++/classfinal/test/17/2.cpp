// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int a[][5] = {  // 数组a用于反映任务效益
//     13, 11, 10, 4, 7,
//     13, 10, 10, 8, 5,
//     5, 9, 7, 7, 4,
//     15, 12, 10, 11, 5,
//     10, 11, 8, 8, 4
// };  // a[i][j]表示第i个人做第j项工作的效益
// f[i] 对应当前第i个人选择方案的编号
// g[i] 对应最高效益的第i个人选择方案的编号
// maxv 对应最高效益和
// tmp用于存储 f 对应的当前效益和
// p[i] 用于表示第i项工作是否已分配，
// p[i]为true说明第i项工作已经分配，为false说明第i项工作还没有分配
// 注意，这里人的编号以及人物的编号都从0开始
int a[5][5];
int n;
int f[5], g[5], maxv, tmp;
bool p[5];
// check函数用于判断f数组当前方案是否比g数组的方案更优
bool check() {
    tmp = 0;          //
    for (int i = 0; i < 5; i ++)    // 因为分配给第i个人的工作编号是p[i]，
        tmp += a[i][ f[i] ];        // 所以tmp需要加上 a[i][ p[i] ]
    return tmp > maxv;
}
// update函数用于更新 g 和 maxv
void update() {
    maxv = tmp;
    for (int i = 0; i < 5; i ++) g[i] = f[i];
}
// dfs函数用于搜过第id个人对应的工作编号
void dfs(int id) {
    if (id == 5) { // 边界条件，说明5个人的工作都分配好了
        if (check()) update();
        return;
    }
    for (int i = 0; i < 5; i ++) {  // i用于遍历工作
        if (p[i] == false) {    // p[i]为false说明第i项工作还没有人做
            f[id] = i;      // 尝试让第id个人做第i项工作
            p[i] = true;    // 同时标记第i项工作已经有人做了
            dfs(id+1);        // 为第id+1个人分配工作
            p[i] = false;   // 回溯回来后我们要确保p[i]重新置为false
        }
    }
}
// output函数用于输出maxv和最高效益方案g
void output() {
    for (int i = 0; i <5; i ++)
        printf("W%-3d", g[i]+1);  // g[i]从0到4，g[i]+1从1到5
    cout << endl;
    cout << maxv << endl;
}
int main() {
	n =5;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    dfs(0);
    output();
    return 0;
}
