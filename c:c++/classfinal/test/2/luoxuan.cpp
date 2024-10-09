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

5 5

    1  2  3  4  5
    6  7  8  9  10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25

9 9

    1  2  3  4  5  6  7  8  9
    10 11 12 13 14 15 16 17 18
    19 20 21 22 23 24 25 26 27
    28 29 30 31 32 33 34 35 36
    37 38 39 40 41 42 43 44 45
    46 47 48 49 50 51 52 53 54
    55 56 57 58 59 60 61 62 63
    64 65 66 67 68 69 70 71 72
    73 74 75 76 77 78 79 80 81

*【输出样例】
1 2 3 6 9 8 7 4 5

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13

1 2 3 4 5 6 7 8 9 18 27 36 45 54 63 72 81 80 79 78 77 76 75 74 73 64 55 46 37 28 19 10 11 12 13 14 15 16 17 26 35 44 53 62 71 70 69 68 67 66 65 56 47 38 29 20 21 22 23 24 25 34 43 52 61 
*/

#include <iostream>
#include <vector>
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


vector<vector<int> > matrixExample(int m,int n){
	vector<vector<int> > matrix(m,vector<int>(n));
	int count =1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			matrix[i][j] =count;
			count++;
		}
	}
	return matrix;
}

int main(){
	int m,n;
	m=3,n=3;
	vector<vector<int> > matrix1 =matrixExample(m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<matrix1[i][j]<< " ";
		}
	}
	cout<<endl;
	f(matrix1,0,0,m,n);
	cout<<endl;

	++m,++n;
	vector<vector<int> > matrix2 =matrixExample(m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<matrix2[i][j]<< " ";
		}
	}
	cout<<endl;
	f(matrix2,0,0,m,n);
	cout<<endl;



	// m =5,n=5;
	m =9,n=9;
	vector<vector<int> > matrixx =matrixExample(m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<matrixx[i][j]<< " ";
		}
	}
	cout<<endl;
	f(matrixx,0,0,m,n);
	cout<<endl;

	// cin>>m>>n;
	// vector<vector<int> > matrix(m,vector<int>(n));
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cin>>matrix[i][j];
	// 	}
	// }
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<matrix[i][j]<< " ";
	// 	}
	// }
	// cout<<endl;
	// f(matrix,0,0,m,n);
	// cout<<endl;

	return 0;
}