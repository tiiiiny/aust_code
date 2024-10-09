// 1036 选数
#include <iostream>
using namespace std;

int n,k,m=0;
int a[21];

bool isprime(int a){
	if(a<2) return false;
	for(int i=2;i*i<=a;i++)
		if(a%i==0)
			return false;
	return true;
}

void dfs(int m,int sum,int startx){
	if(m==k) {
		if(isprime(sum))
			m++;
		return;
	}
	for(int i = startx;i<n;i++){
		dfs(m+1,sum+a[i],i+1);
	}
	cout<<m;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){cin>>a[i];}
	dfs(0,0,0);
	return 0;
}