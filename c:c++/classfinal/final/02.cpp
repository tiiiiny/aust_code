/*
* 2.螺旋阵（基础算法） 
*【问题描述】
*请设计算法完成螺旋阵的输出，具有要求为：
*输入一个 m 行 n 列的矩阵，
*按顺时针螺旋顺序输出矩阵中的所有元素。
*【输入】
*第 1 行输入两个正整数 m 和 n，表示 m 行 n 列的矩阵；
*从第 2 行开始按行输入该矩阵的所有元素。
*【输出】
*按顺时针螺旋顺序输出矩阵中的所有元素，每个元素之间用空格隔开。
*【输入样例】
3 3
1 2 3 
4 5 6 
7 8 9 

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 4
1  2  3  4
5  6  7  8
9 10 11 12 

5 4
1  2  3  4
5  6  7  8 
9 10 11 12
13 14 15 16
17 18 19 20

*【输出样例】
1 2 3 6 9 8 7 4 5

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

1 2 3 4 8 12 11 10 9 5 6 7

1 2 3 4 8 12 16 20 19 18 17 13 9 5 6 7 11 15 14 10 
*/

#include <iostream>
#include <vector>

using namespace std;

void clockWise(const vector<vector<int>>& matrix, int sx, int sy, int ex, int ey) { 
    if (ex <= sx || ey <= sy) // 内矩阵为空
        return;
    
    // 内矩阵只有一行，遍历每列
    if (sx == ex - 1) {			
        for (int j = sy; j < ey; ++j) {
            cout << matrix[sx][j] << (j < ey - 1 ? " " : "");
        }
        return;
    }
    // 内矩阵只有一列，遍历每行
    if (sy == ey - 1) {
        for (int i = sx; i < ex; ++i) {
            cout << matrix[i][sy] << (i < ex - 1 ? " " : "");
        }
        return;
    }

    // 从左到右遍历最上面一行
    for (int j = sy; j < ey; ++j) {
        cout << matrix[sx][j] << " ";
    }
    // 从上到下遍历最右边一列
    for (int i = sx + 1; i < ex; ++i) {
        cout << matrix[i][ey - 1] << " ";
    }
    // 从右到左遍历最下面一行
    for (int j = ey - 2; j >= sy; --j) {
        cout << matrix[ex - 1][j] << " ";
    }
    // 从下到上遍历最左边一列
    for (int i = ex - 2; i > sx; --i) {
        cout << matrix[i][sy] << " ";
    }
    // 递归处理内部的矩阵
    clockWise(matrix, sx + 1, sy + 1, ex - 1, ey - 1);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    clockWise(matrix, 0, 0, m, n);
    cout << endl;

    return 0;
}
