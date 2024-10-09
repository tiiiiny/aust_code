// 9011
// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

int n,m,k,ans=1e9,cw[105],s[25],t[25],c[25],a[25],b[25],p[25],v[25];

bool f()//是否满足
{
	for(int i=1;i<=k;i++)
	{
		if(cw[i]>0) return 0;
	}
	return 1;
}

void dfs(int dep,int s)
{
	if(dep>m)
	{
		//cerr<<"DE: ";for(int i=1;i<=k;i++) cerr<<cw[i]<<' ';cerr<<endl;
		if(f()) ans=min(ans,s);//合法就更新答案
		return;
	}
	dfs(dep+1,s);//不选
	for(int i=a[dep];i<=b[dep];i++) cw[i]-=p[dep];
	dfs(dep+1,s+v[dep]);//选
	for(int i=a[dep];i<=b[dep];i++) cw[i]+=p[dep];//回溯
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i]>>c[i];
		k=max(k,t[i]);
		for(int j=s[i];j<=t[i];j++) cw[j]+=c[i];//事先处理
	}
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>p[i]>>v[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}




/*#include <iostream>
using namespace std;

int N;
// int a[101];
int s[101],t[101],c[101];

int M;
int m[1001];
int a[101],b[101],p[101];



void solve(){
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>s[i]>>t[i]>>c[i];
	for(int i=1;i<=M;i++) cin>>a[i]>>b[i]>>p[i]>>m[i];
}



int main(){
	solve();

	return 0;
}*/