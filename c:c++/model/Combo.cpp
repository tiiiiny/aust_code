// C++组合学Combonatorics全套模板

// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
// #include<algorithm>
// #include<cmath>
// #include<cstdio>

// #include<cstring>
// #include<string>
// #include<cstdlib>
// #include<ctime>
// #include<queue>
// #include<set>
// #include<map>
// #include<stack>
// #include<list>
// #include<deque>
// #include<iomanip>
// #include<complex>
// #include<climits>
// #include<cfloat>
// #include<ciso646>
// #include<fstream>
// #include<sstream>
#include<ios>
// #include<stdexcept>

using namespace std;

class Combo{
private:
	long long p;
	vector<long long> f,invf,subf;
	long long invfact(long long x){
		if(x>=invf.size()) 
			invf.resize(x+1,-1);
		if(invf[x]!=-1) 
			return invf[x];
		return invf[x]=inv(fact(x));
	}
public:
	Combo(long long P){
		p=P;
		f={1,1};
		invf={1,1};
		subf={1,0};
	}
	long long exp(long long x,long long y){
		long long res=1;
		while(y>0){
			if(y%2==1) res=res*x%p;
			x=x*x%p;
			y/=2;
	}
	return res;
	}

	long long inv(long long x){
		return exp(x,p-2);
	}

	long long fact(long long x){
		if(x<f.size()) return f[x];
		long long i,oldsize=f.size();
		f.resize(x+1);
		for(i=oldsize;i<=x;i++) f[i]=f[i-1]*i%p;
		return f[x];
	}

	long long binom(long long n,long long k){
		return (fact(n)*invfact(n-k)%p)*invfact(k)%p;
	}

	long long subfact(long long x){
		if(x<subf.size()) return subf[x];
		long long i,oldsize=subf.size();
		subf.resize(x+1);
		for(i=oldsize;i<=x;i++) subf[i]=(i-1)*((subf[i-1]+subf[i-2])%p)%p;
		return subf[x];
	}

	long long Catalan(long long x){
		return binom(2*x,x)*inv(x+1)%p;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//定义一个Combo object

	//以下它的所有计算都是mod P，P要求是质数
	//Combo c(long long P);

	//计算x^y

	//long long c.exp(long long x,long long y);


	//计算x的倒数multiplicative inverse

	//long long c.inv(long long x);

	//计算x的阶乘: x!

	//long long c.fact(long long x);



	//计算二项式系数n choose k

	//long long c.binom(long long n,long long k);
	
	//计算x的subfactorial: !x

	//!x表示有多少个1到x的排列使得每个数都不在自己的原位上 

	//long long c.subfact(long long x);

	//计算第x个卡特兰数

	//第x个卡特兰数表示x对括号能排成多少个不同的合法括号序列

	//例如x=2有两种: (())和()()

	//long long c.Catalan(long long x);

	// system("pause");

	return 0;

}