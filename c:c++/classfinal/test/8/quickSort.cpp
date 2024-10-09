
#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e6+100;
int a[N];
    //做一次划分，归位基准数
int p(int num[],int l,int r){
    int temp=num[l];
    while(l<r){
		while(l<r&&num[r]>temp) 
			r--;
		num[l]=num[r];
		while(l<r&&num[l]<=temp) 
			l++;
		num[r]=num[l];
    }
    num[l]=temp;
    return l;
}
    //分治查找第k小的数
int quicksort(int num[],int l,int r,int k){
	int x=p(num,l,r);
	if(x==k) 
		return num[k];
	return x>k ? quicksort(num,l,x-1,k) :  quicksort(num,x+1,r,k);
}
int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
		scanf("%d",&a[i]);
    scanf("%d",&k);
    printf("%d\n",quicksort(a,0,n-1,k-1));
    return 0;
}

