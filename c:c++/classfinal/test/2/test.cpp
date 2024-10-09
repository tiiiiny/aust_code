/*
* 2.螺旋阵（基础算法） 
*【问题描述】
*请设计算法完成螺旋阵的输出，具有要求为：
输入一个 m 行 n 列的矩阵，
按顺时针螺旋顺序输出矩阵中的所有元素。
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
    1  2  3  4
    5  6  7  8
    9  10 11 12
    13 14 15 16
*【输出样例】
1 2 3 6 9 8 7 4 5

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/


#include <iostream>
using namespace std;

void f(vector<vector<int> > matrix,int sx,int sy,int ex,int ey){ //,0,0,4,4;,1,1,3,3;,2,2,2,2
	 															// ,0,0,3,3;,1,1,2,2;,2,2,1,1
	// for(int i=sx;i<ex;i++){
		// int i = sx;
		// if(sx==ex-1){
		// 	if(sy==ey-1){
		if(sx==ex-1 && sy==ey-1){
			cout<<matrix[sx][sy]<<" ";	// 5
			return;
		
		}
		if(ex<=sx && ey<=sy )
			return;
		for(int j=sy;j<ey;j++){
			cout<<matrix[sx][j]<<" ";	// 1 2 3 4,6 7
		}
		for(int k=sx+1;k<ex;k++){
			cout<<matrix[k][ey-1]<<" ";	// 8 12 16,11
		}
		for(int l=ey-2;l>=sx;l--){
			cout<<matrix[ex-1][l]<<" ";	// 16 14 13,10
		}
		for(int t=ex-2;t>=sx+1;t--){
			cout<<matrix[t][sy]<<" ";	// 9 5,..
		}
	// }
	f(matrix,sx+1,sy+1,ex-1,ey-1);
};




int main(){
	int m,n;
	// m=3,n=3;
	// vector<vector<int> > matrix(m,vector<int>(n));
	// matrix[0][0] = 1;
	// matrix[0][1] = 2;
	// matrix[0][2] = 3;
	// matrix[1][0] = 4;
	// matrix[1][1] = 5;
	// matrix[1][2] = 6;
	// matrix[2][0] = 7;
	// matrix[2][1] = 8;
	// matrix[2][2] = 9;
	m=4,n=4;
	vector<vector<int> > matrix(m,vector<int>(n));
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[0][3] = 4;
	matrix[1][0] = 5;
	matrix[1][1] = 6;
	matrix[1][2] = 7;
	matrix[1][3] = 8;
	matrix[2][0] = 9;
	matrix[2][1] = 10;
	matrix[2][2] = 11;
	matrix[2][3] = 12;
	matrix[3][0] = 13;
	matrix[3][1] = 14;
	matrix[3][2] = 15;
	matrix[3][3] = 16;
	f(matrix,0,0,m,n);

	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<matrix[i][j];
	// 	}
	// }


	return 0;
}