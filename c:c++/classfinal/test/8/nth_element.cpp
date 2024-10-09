//AC代码：
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=5e6+100;
int a[N];
    int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    nth_element(a,a+k,a+n);   
    printf("%d\n",a[k-1]);
    return 0;
    }
