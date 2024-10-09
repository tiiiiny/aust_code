/*
* 最大工作效益（回溯
*【输入样例】
13 11 10 4 7
13 10 10 8 5
5 9 7 7 4
15 12 10 11 5
10 11 8 8 4

29 38 33 27 3
2 43 40 34 23
22 34 55 1 34
23 45 35 47 52
41 31 42 28 17

*【输出样例】
W5 W3 W4 W1 W2
50

W2 W4 W3 W5 W1
220
*/

#include <iostream>
using namespace std;

int a[5][5];
int n;
int f[5], g[5], maxv, tmp;
bool p[5];

bool check() {
    tmp = 0;          //
    for (int i = 0; i < 5; i ++)
        tmp += a[i][ f[i] ];
    return tmp > maxv;
}

void update() {
    maxv = tmp;
    for (int i = 0; i < 5; i ++) g[i] = f[i];
}

void dfs(int id) {
    if (id == 5) { 
        if (check()) update();
        return;
    }
    for (int i = 0; i < 5; i ++) {
        if (p[i] == false) {
            f[id] = i;
            p[i] = true;
            dfs(id+1);
            p[i] = false;
        }
    }
}

void output() {
    for (int i = 0; i <5; i ++)
        printf("W%-3d", g[i]+1);
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
